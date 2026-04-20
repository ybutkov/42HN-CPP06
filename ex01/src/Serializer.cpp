#include "Serializer.hpp"
#include "Data.hpp"


uintptr_t Serializer::serialize(Data* ptr)
{
      uintptr_t address = reinterpret_cast<uintptr_t> (ptr);
      return address;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* dataObj = reinterpret_cast<Data*> (raw);
    return dataObj;
}
