#include <cstdint>
#include <bit>
#include <array>

#ifndef BLACK_HOLE_HASH_HPP
#define BLACK_HOLE_HASH_HPP


//بسم الله الرحمن الرحيم 

namespace hbh {

    inline uint32_t byte_collector(uint8_t,uint8_t,uint8_t,uint8_t);
    inline void bug_transformer(uint32_t,uint32_t,uint32_t,uint32_t);
    inline void letter_map_lock(uint32_t,uint32_t,uint32_t,uint32_t);
    inline void letter_map_unlock(uint32_t ,uint32_t,uint32_t,uint32_t);
    inline uint8_t cutter(uint32_t);
    inline uint32_t I(uint32_t,uint32_t,uint32_t,uint32_t);
    inline void G(uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t, uint32_t);
    inline uint32_t hanfozlik(uint32_t,uint32_t,uint32_t,uint32_t);
    inline uint32_t potato(uint32_t,uint32_t,uint32_t,uint32_t,uint32_t);
    inline uint32_t T(uint32_t,uint32_t,uint32_t);
    inline uint32_t final(uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t, uint32_t);


    inline uint32_t byte_collector(uint8_t byte_1,uint8_t byte_2,uint8_t byte_3,uint8_t byte_4){
        return static_cast<uint32_t>(static_cast<uint32_t>(byte_1) ^ ((static_cast<uint32_t>(byte_2)>>8))^((static_cast<uint32_t>(byte_3)>>16))^ ((static_cast<uint32_t>(byte_4)>>24)));
    }

    inline void bug_transformer(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3){
        uint32_t t;

        t = (r0 ^ (r2 >> 2)) & 0x33333333;
        r0 ^= t;
        r2 ^= (t << 2);
        t = (r1 ^ (r3 >> 2)) & 0x33333333; r1 ^= t;
        r3 ^= (t << 2);
    
        t = (r0 ^ (r1 >> 1)) & 0x55555555;
        r0 ^= t;
        r1 ^= (t << 1);
        t = (r2 ^ (r3 >> 1)) & 0x55555555;
        r2 ^= t;
        r3 ^= (t << 1);
    }

    std::array<void(*)(uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4),36> letter_map={
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r3 ^= r0;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 = r1;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 &= r3;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 ^= r2;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 ^= r0;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r0 |= r3;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r0 ^= r4;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 ^= r3;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r3 ^= r2;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r2 |= r1;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r2 ^= r4;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 = ~r4;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 |= r1;},            [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 ^= r3;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 ^= r4;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r3 |= r0;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 ^= r3;},            [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 ^= r3;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r3 = r0;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r0 = r1;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 = r4;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 ^= r2;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 ^= r0;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r0 |= r3;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r0 ^= r4;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 ^= r3;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r3 ^= r2;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r2 |= r1;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r2 ^= r4;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 = ~r4;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 |= r1;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 ^= r3;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 ^= r4;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r3 |= r0;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r1 ^= r3;},
        [](uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4){r4 ^= r3;},

    };


    inline void letter_map_unlock(uint32_t r0,uint32_t r1,uint32_t r2,uint32_t r3){
        uint32_t r4 =0;
        r1 = r4;
        r0 = r1;
        r3 = r0;
        r4 ^= r3;
        r1 ^= r3;
        r3 |= r0;
        r1 ^= r4;
        r1 ^= r3;
        r4 |= r1;
        r4 = ~r4;
        r2 ^= r4;
        r2 |= r1;
        r3 ^= r2;
        r4 ^= r3;
        r0 ^= r4;
        r0 |= r3;
        r1 ^= r0;
        r4 ^= r2;
        r1 &= r3;
        r4 = r1;
        r3 ^= r0;
    }



    inline uint8_t cutter(uint32_t value){
        return (value & 0xFF)^  ((value >> 8) & 0xFF) ^ ((value >> 16) & 0xFF) ^ ((value >> 24) & 0xFF);
    }


    inline uint32_t I(uint32_t a,uint32_t b,uint32_t c,uint32_t d){
        uint8_t a_1 = (a & 0xFF);uint8_t b_1 = ((b >> 8) & 0xFF);
        uint8_t c_1 = ((c >> 16) & 0xFF);uint8_t d_1 = ((d >> 24) & 0xFF);
        return (std::rotr(a_1,cutter(b)))^ static_cast<uint32_t>((std::rotl(b_1,cutter(c))) << 8) ^ static_cast<uint32_t>((static_cast<unsigned char>(c_1 + d))  << 16) ^ static_cast<uint32_t>((static_cast<unsigned char>(d_1 - a)) << 24);
    }

    inline void G(uint32_t &a, uint32_t &b, uint32_t &c, uint32_t &d, uint32_t m0, uint32_t m1){

        uint32_t* values[4] = {&a,&b,&c,&d};
        std::swap(values[0],values[hanfozlik(1,d,c,b)&3]);
        std::swap(values[1],values[hanfozlik(1,d,c,b)&3]);
        std::swap(values[2],values[hanfozlik(1,d,c,b)&3]);
        std::swap(values[3],values[hanfozlik(1,d,c,b)&3]);
        
        a = a + b + m0;
        a =std::rotl(a,b + (b ^ (a + c)));
        b = a + m1;
        b =std::rotl(b,a + (a ^ (d + c)));
        d = c + (m1 ^ m0);
        d =std::rotl(d,a + (a ^ (d + b)));
        c = (a & b) ^ (c & b) ^ (b & d)^ (~a & d);
        c =std::rotl(c,d + (d ^ (a + a)));
    }
    inline uint32_t hanfozlik(uint32_t a,uint32_t b,uint32_t c,uint32_t d){
        
        uint32_t* values[4] = {&a,&b,&c,&d};
        std::swap(values[0],values[hanfozlik(1,d,c,b)&3]);
        std::swap(values[1],values[hanfozlik(1,d,c,b)&3]);
        std::swap(values[2],values[hanfozlik(1,d,c,b)&3]);
        std::swap(values[3],values[hanfozlik(1,d,c,b)&3]);

        a = ((~a) * (~a)) + (((~a) * (~a)) | 1);
        b = b = ((~b) * (~b)) + (((~b) * (~b)) | 2);
        c = c = ((~c) * (~c)) + (((~c) * (~c)) | 4);
        d = ((~d) * (~d)) + (((~d) * (~d)) | 16);
        a ^= std::rotl(a,b & 31) + std::rotl(a,c & 31) + std::rotl(a,d & 31);
        b ^= std::rotl(b,a & 31) + std::rotl(b,c & 31) + std::rotl(b,d & 31);
        c ^= std::rotl(c,b & 31) + std::rotl(c,a & 31) + std::rotl(c,d & 31);
        d ^= std::rotl(d,b & 31) + std::rotl(d,c & 31) + std::rotl(d,a & 31);
            
        
        return (a ^ ((b + c) ^ d)) + 
        ((a - (b ^ c)) + d) - 
        (std::rotr(a,b & 31) + std::rotl(c,d & 31)) + 
        (std::rotl(std::rotr(a,(c ^ b)& 31),std::rotl(b,(d ^ a)& 31)) - std::rotr(std::rotr(d,(b ^ d)& 31),std::rotl(c,(b ^ c)& 31)));
    }

    inline uint32_t potato(uint32_t x,uint32_t y ,uint32_t z,uint32_t world_size_x,uint32_t world_size_z){
        uint32_t mask_z = z + (world_size_z ^ y);
        uint32_t mask_x = x + (world_size_x ^ mask_z);
        return std::rotl(mask_x,mask_z & 0x1F);
    }
    inline uint32_t T(uint32_t y,uint32_t z,uint32_t x){
        uint32_t k = (x & y) ^ (x & z) ^ (y & z)^ (~x & z)^ (std::rotl(x,((~x & z) & 31)));
        uint32_t p = k + (~k ^ std::rotl(k,~k & 31  - ((x & y) ^ (x & z) ^ (y & z)^ (~x & z))));
        uint32_t c = ((((p >> 24) & 0xFF) + ((p >> 16) & 0xFF)) ^ ((p >> 8)  & 0xFF)) + p;
        c += (c * c) | ((c - p) | 1);
        return std::rotl(p + c, 7) ^ std::rotr(p - c, 11);
    }

    inline uint32_t final(uint32_t &a, uint32_t &b, uint32_t &c, uint32_t &d, uint32_t m0, uint32_t m1){
        uint32_t result{};
        uint32_t* values[4] = {&a,&b,&c,&d};
        std::swap(values[0],values[hanfozlik(1,d,c,b)&3]);
        std::swap(values[1],values[hanfozlik(1,d,c,b)&3]);
        std::swap(values[2],values[hanfozlik(1,d,c,b)&3]);
        std::swap(values[3],values[hanfozlik(1,d,c,b)&3]);


        a = hanfozlik(d, a, b, c);
        b = hanfozlik(d,b,a,c);
        c = hanfozlik(a,d,b,c);
        d = hanfozlik(a,b,c,d);
            

        std::array<void(*)(uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t, uint32_t,uint32_t&),4>fun = {
            [](uint32_t &a, uint32_t &b, uint32_t &c, uint32_t &d, uint32_t m0, uint32_t m1,uint32_t& result){G(a,b,c,d,m0,m1);},
            [](uint32_t &a, uint32_t &b, uint32_t &c, uint32_t &d, uint32_t m0, uint32_t m1,uint32_t& result){result = T(a,b,c + d);},
            [](uint32_t &a, uint32_t &b, uint32_t &c, uint32_t &d, uint32_t m0, uint32_t m1,uint32_t& result){result = potato(a,b,c,d,result);},
            [](uint32_t &a, uint32_t &b, uint32_t &c, uint32_t &d, uint32_t m0, uint32_t m1,uint32_t& result){result = I(a,b,c,result);}
        };
        std::swap(fun[0],fun[hanfozlik(1,d,c,b)&3]);
        std::swap(fun[1],fun[hanfozlik(1,d,c,b)&3]);
        std::swap(fun[2],fun[hanfozlik(1,d,c,b)&3]);
        std::swap(fun[3],fun[hanfozlik(1,d,c,b)&3]);

        fun[0](a,b,c,d,m0,m1,result);
        fun[1](a,b,c,d,m0,m1,result);
        fun[2](a,b,c,d,m0,m1,result);
        fun[3](a,b,c,d,m0,m1,result);


        

        
        return result;
    }
}

#endif