/*!
 *  \file       mcal_reg_access.hpp
 *  \brief      
 *  
 */


#pragma once


namespace mcal
{
    namespace reg
    {
        template<typename register_address_type,
                 typename register_value_type,
                 const register_address_type    address,
                 const register_value_type      value = static_cast<register_value_type>(0)>
        struct reg_access_static final
        {
            static void reg_set();
            static void reg_and();
            static void reg_or ();
            static void reg_not();

            static register_value_type reg_get();
            template<const register_value_type mask_value> static void reg_msk();
            
            static void bit_set();
            static void bit_clr();
            static void bit_not();
            static bool bit_get();
        };


        template<typename register_address_type,
                 typename register_value_type>
        struct reg_access_dynamic final
        {
            static register_value_type reg_get(const register_address_type address);

            static void reg_set(const register_address_type address, const register_value_type value);
            static void reg_and(const register_address_type address, const register_value_type value);
            static void reg_or (const register_address_type address, const register_value_type value);
            static void reg_not(const register_address_type address, const register_value_type value);
            static void reg_msk(const register_address_type address, const register_value_type value, const register_value_type mask_value);

            static void bit_set(const register_address_type address, const register_value_type value);
            static void bit_clr(const register_address_type address, const register_value_type value);
            static void bit_not(const register_address_type address, const register_value_type value);
            static bool bit_get(const register_address_type address, const register_value_type value);
        };
    }
}

