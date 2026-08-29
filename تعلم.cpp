
#include <vector>
#include <cstdint>
#include <array>
#include <algorithm>
#include <utility>
#include <string_view>
#include <string>
#include <numeric>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include "mybinary/black_hole_hash.hpp"
#include "mybinary/spun.hpp"


//bit_scill eat 16bit for time that mean every small loop i use 16bit*small_loop_times that mean every bigloop i use 16bit*small_loop_times*big_loops_time that mean
//region.flush();^ %
// decltype(a)
namespace vfb {



    void state_and_key_gen_and_key_map(std::array<uint32_t, 16>& letter_states,std::array<uint32_t, 16>& letter_keys,spun<uint8_t> key_file_matrix){
        std::iota(letter_keys.begin(), letter_keys.end(), key_file_matrix[1]);
        std::iota(letter_states.begin(), letter_states.end(), key_file_matrix[0]);
        std::reverse(letter_keys.begin(), letter_keys.end());
        std::reverse(letter_states.begin(), letter_states.end());
        for (uint8_t i = 0; i < 16; i++)
        {
            std::swap(letter_keys[i],letter_keys[key_file_matrix[i]&15]);
            std::swap(letter_states[i],letter_states[key_file_matrix[i]&15]);
        }
        std::transform(letter_states.begin(), letter_states.end(), letter_states.begin(), [](uint32_t val) {
            return hbh::final(val,val,val,val,val,val);
        });
        std::transform(letter_keys.begin(), letter_keys.end(), letter_keys.begin(), [](uint32_t val) {
            return hbh::final(val,val,val,val,val,val);
        });
    }



    inline uint32_t potato(size_t i,uint8_t byite_num){return byite_num+i;}
    inline void basic_flash(spun<uint8_t> file_matrix,const size_t chunk_size,std::array<uint32_t, 16>& letter_states,std::array<uint32_t, 16>& letter_keys,size_t i,spun<uint8_t> key_file_matrix){
        uint32_t byte_1 = hbh::byte_collector(file_matrix[potato(i,1)],file_matrix[potato(i,2)],file_matrix[potato(i,3)],file_matrix[potato(i,4)]);
        uint32_t byte_2 = hbh::byte_collector(file_matrix[potato(i,5)],file_matrix[potato(i,6)],file_matrix[potato(i,7)],file_matrix[potato(i,8)]);;
        uint32_t byte_3 = hbh::byte_collector(file_matrix[potato(i,9)],file_matrix[potato(i,10)],file_matrix[potato(i,11)],file_matrix[potato(i,12)]);
        uint32_t byte_4 = hbh::byte_collector(file_matrix[potato(i,13)],file_matrix[potato(i,14)],file_matrix[potato(i,15)],file_matrix[potato(i,16)]);

        hbh::bug_transformer(byte_1,byte_2,byte_3,byte_4);
        uint32_t r4{};
        std::array<void(*)(uint32_t& r0,uint32_t& r1,uint32_t& r2,uint32_t& r3,uint32_t& r4),36> letter_map = hbh::letter_map;
        for (uint8_t i = 0; i < 32; i++)
        {
            std::swap(letter_map[i],letter_map[i^letter_states[(i+(16^letter_keys[(i+15)&15]))&15]]);
        }
        for (uint8_t i = 0; i < 32; i++)
        {
            letter_map[i](byte_1,byte_2,byte_3,byte_4,r4);
        }
        uint32_t bong = hbh::final(letter_keys[i&15],letter_states[i],letter_keys[i&15],letter_states[i&15],letter_states[i&15]^letter_states[i&15],letter_keys[i&15]^key_file_matrix[(letter_states[i&15]^letter_states[i&15])]);
        byte_1 ^=bong^key_file_matrix[0]^letter_states[2];
        byte_2 ^=bong^key_file_matrix[0]^letter_keys[3];
        byte_3 ^=bong^key_file_matrix[0]^letter_states[4];
        byte_4 ^=bong^key_file_matrix[0]^letter_keys[5];

        letter_states[(i)&15] ^=byte_1;
        letter_keys[(i)&15] ^=byte_4;



        file_matrix[potato(i,1)] = static_cast<uint8_t>(byte_1);
        file_matrix[potato(i,2)] = static_cast<uint8_t>(byte_1<<8);
        file_matrix[potato(i,3)] = static_cast<uint8_t>(byte_1<<16);
        file_matrix[potato(i,4)] = static_cast<uint8_t>(byte_1<<24);

        file_matrix[potato(i,5)] = static_cast<uint8_t>(byte_2);
        file_matrix[potato(i,6)] = static_cast<uint8_t>(byte_2<<8);
        file_matrix[potato(i,7)] = static_cast<uint8_t>(byte_2<<16);
        file_matrix[potato(i,8)] = static_cast<uint8_t>(byte_2<<24);

        file_matrix[potato(i,9)] = static_cast<uint8_t>(byte_3);
        file_matrix[potato(i,10)] = static_cast<uint8_t>(byte_3<<8);
        file_matrix[potato(i,11)] = static_cast<uint8_t>(byte_3<<16);
        file_matrix[potato(i,12)] = static_cast<uint8_t>(byte_3<<24);

        file_matrix[potato(i,13)] = static_cast<uint8_t>(byte_4);
        file_matrix[potato(i,14)] = static_cast<uint8_t>(byte_4<<8);
        file_matrix[potato(i,15)] = static_cast<uint8_t>(byte_4<<16);
        file_matrix[potato(i,16)] = static_cast<uint8_t>(byte_4<<24);

    }

    void letter_lock(std::string file_name,std::string key_file_path){


        boost::interprocess::file_mapping m_file(file_name.c_str(),boost::interprocess::read_write);
        boost::interprocess::mapped_region region(m_file,boost::interprocess::read_write);
        spun<uint8_t> file_matrix{static_cast<uint8_t*>(region.get_address()),region.get_size()};

        boost::interprocess::file_mapping k_file(file_name.c_str(),boost::interprocess::read_write);
        boost::interprocess::mapped_region key_region(m_file,boost::interprocess::read_write);
        spun<uint8_t> key_file_matrix{static_cast<uint8_t*>(region.get_address()),region.get_size()};

        std::array<uint32_t,16>letter_states{},letter_keys{};
        state_and_key_gen_and_key_map(letter_states,letter_keys,key_file_matrix);

        const size_t chunk_size = 64;

        for (size_t i = 0; i < file_matrix.size; i+=16)
        {
            basic_flash(file_matrix,chunk_size,letter_states,letter_keys,i,key_file_matrix);
            region.flush();
        }



    };


}


int main() {

    return 0;
}
