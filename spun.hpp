#include <cstdint>



template <typename T>
struct medum
{
    T* read_pointer;
    T* write_pointer;

    operator T() const{return *read_pointer;};

    void operator=(T val){*write_pointer = val;};
};

template <typename T>
struct spun
{
    T* pointer{};
    std::size_t size{};

    medum<T> operator[](std::size_t index){
        static T trash{};
        static const T read{};

        

        intptr_t mask = -(index < size);
        intptr_t safe_index = index & mask;
        intptr_t real_address =  reinterpret_cast<intptr_t>(pointer + safe_index);
        intptr_t trash_ptr = reinterpret_cast<intptr_t>(&trash);
        intptr_t read_ptr = reinterpret_cast<intptr_t>(&read);

        intptr_t r_tp = (real_address & mask) | (read_ptr & (~mask));
        intptr_t w_tp = (real_address & mask) | (trash_ptr & (~mask));

        return medum<T>{reinterpret_cast<T*>(r_tp),reinterpret_cast<T*>(w_tp)};
    }
    
};