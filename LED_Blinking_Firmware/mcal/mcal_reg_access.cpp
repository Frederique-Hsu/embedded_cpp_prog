/*!
 *  \file       mcal_reg_access.cpp
 *  \brief      
 *  
 */


#include "mcal_reg_access.hpp"

namespace mcal
{
namespace reg
{
    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    void reg_access_static<register_address_type, register_value_type, address, value>::reg_set()
    {
        *reinterpret_cast<volatile register_value_type*>(address) = value;
    }

    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    void reg_access_static<register_address_type, register_value_type, address, value>::reg_and()
    {
        *reinterpret_cast<volatile register_value_type*>(address) &= value;
    }

    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    void reg_access_static<register_address_type, register_value_type, address, value>::reg_or()
    {
        *reinterpret_cast<volatile register_value_type*>(address) |= value;
    }

    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    void reg_access_static<register_address_type, register_value_type, address, value>::reg_not()
    {
        *reinterpret_cast<volatile register_value_type*>(address) &= register_value_type(~value);
    }

    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    register_value_type reg_access_static<register_address_type, register_value_type, address, value>::reg_get()
    {
        return *reinterpret_cast<volatile register_value_type*>(address);
    }

    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    template<const register_value_type      mask_value>
    void reg_access_static<register_address_type, register_value_type, address, value>::reg_msk()
    {
        register_value_type new_value = (reg_get() & (~mask_value)) | (value & mask_value);

        *reinterpret_cast<volatile register_value_type*>(address) = new_value;
    }

    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    void reg_access_static<register_address_type, register_value_type, address, value>::bit_set()
    {
        register_value_type bit_value = static_cast<register_value_type>(0x0001ULL << value);
        *reinterpret_cast<volatile register_value_type*>(address) |= bit_value;
    }

    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    void reg_access_static<register_address_type, register_value_type, address, value>::bit_clr()
    {
        register_value_type bit_value = ~static_cast<register_value_type>(0x0001ULL << value);
        *reinterpret_cast<volatile register_value_type*>(address) &= bit_value;
    }

    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    void reg_access_static<register_address_type, register_value_type, address, value>::bit_not()
    {
        register_value_type bit_value = static_cast<register_value_type>(0x0001ULL << value);
        *reinterpret_cast<volatile register_value_type*>(address) ^= bit_value;
    }

    template<typename register_address_type, 
             typename register_value_type,
             const register_address_type    address,
             const register_value_type      value>
    bool reg_access_static<register_address_type, register_value_type, address, value>::bit_get()
    {
        register_value_type bit_value = (reg_get() & static_cast<register_value_type>(0x0001ULL << value));
        return (bit_value != static_cast<register_value_type>(0x0000U));
    }

    template<typename register_address_type, typename register_value_type>
    register_value_type reg_access_dynamic<register_address_type, register_value_type>::reg_get(
        const register_address_type address)
    {
        return *reinterpret_cast<volatile register_value_type*>(address);
    }

    template<typename register_address_type, typename register_value_type>
    void reg_access_dynamic<register_address_type, register_value_type>::reg_set(
        const register_address_type address, const register_value_type value)
    {
        *reinterpret_cast<volatile register_value_type*>(address) = value;
    }

    template<typename register_address_type, typename register_value_type>
    void reg_access_dynamic<register_address_type, register_value_type>::reg_and(
        const register_address_type address, const register_value_type value)
    {
        *reinterpret_cast<volatile register_value_type*>(address) &= value;
    }

    template<typename register_address_type, typename register_value_type>
    void reg_access_dynamic<register_address_type, register_value_type>::reg_or(
        const register_address_type address, const register_value_type value)
    {
        *reinterpret_cast<volatile register_value_type*>(address) |= value;
    }

    template<typename register_address_type, typename register_value_type>
    void reg_access_dynamic<register_address_type, register_value_type>::reg_not(
        const register_address_type address, const register_value_type value)
    {
        *reinterpret_cast<volatile register_value_type*>(address) &= register_value_type(~value);
    }

    template<typename register_address_type, typename register_value_type>
    void reg_access_dynamic<register_address_type, register_value_type>::reg_msk(
        const register_address_type address, const register_value_type value, const register_value_type mask_value)
    {
        register_value_type new_value = (reg_get(address) & register_value_type(~mask_value)) | (value & mask_value);
        *reinterpret_cast<volatile register_value_type*>(address) = new_value;
    }

    template<typename register_address_type, typename register_value_type>
    void reg_access_dynamic<register_address_type, register_value_type>::bit_set(
        const register_address_type address, const register_value_type value)
    {
        register_value_type bit_value = static_cast<register_value_type>(0x0001ULL << value);
        *reinterpret_cast<volatile register_value_type*>(address) |= bit_value;
    }

    template<typename register_address_type, typename register_value_type>
    void reg_access_dynamic<register_address_type, register_value_type>::bit_clr(
        const register_address_type address, const register_value_type value)
    {
        register_value_type bit_value = ~static_cast<register_value_type>(0x0001ULL << value);
        *reinterpret_cast<volatile register_value_type*>(address) &= bit_value;
    }

    template<typename register_address_type, typename register_value_type>
    void reg_access_dynamic<register_address_type, register_value_type>::bit_not(
        const register_address_type address, const register_value_type value)
    {
        register_value_type bit_value = static_cast<register_value_type>(0x0001ULL << value);
        *reinterpret_cast<volatile register_value_type*>(address) ^= bit_value;
    }

    template<typename register_address_type, typename register_value_type>
    bool reg_access_dynamic<register_address_type, register_value_type>::bit_get(
        const register_address_type address, const register_value_type value)
    {
        register_value_type bit_value = (reg_get(address) & static_cast<register_value_type>(0x0001ULL << value));
        return (bit_value != static_cast<register_value_type>(0x0000U));
    }
}
}
