// Copyright (c)   2021     
//      
//   

#include "Denominations.h"
#include "amount.h"

namespace libzero  {
// All denomination values should only exist in these routines for consistency.
// For serialization/unserialization enums are converted to int (denoted enumvalue in function name)

 Denomination IntToZero Denomination(int64_t amount)
{
     Denomination denomination;
    switch (amount) {
    case 1:        denomination =  Denomination::ZQ_ONE; break;
    case 5:    denomination =  Denomination::ZQ_FIVE; break;
    case 10:    denomination =  Denomination::ZQ_TEN; break;
    case 50:    denomination =  Denomination::ZQ_FIFTY; break;
    case 100: denomination =  Denomination::ZQ_ONE_HUNDRED; break;
    case 500: denomination =  Denomination::ZQ_FIVE_HUNDRED; break;
    case 1000: denomination =  Denomination::ZQ_ONE_THOUSAND; break;
    case 5000: denomination =  Denomination::ZQ_FIVE_THOUSAND; break;
    default:
        //not a valid denomination
        denomination =  Denomination::ZQ_ERROR; break;
    }

    return denomination;
}

int64_t Zero DenominationToInt(const  Denomination& denomination)
{
    int64_t Value = 0;
    switch (denomination) {
    case  Denomination::ZQ_ONE: Value = 1; break;
    case  Denomination::ZQ_FIVE: Value = 5; break;
    case  Denomination::ZQ_TEN: Value = 10; break;
    case  Denomination::ZQ_FIFTY : Value = 50; break;
    case  Denomination::ZQ_ONE_HUNDRED: Value = 100; break;
    case  Denomination::ZQ_FIVE_HUNDRED: Value = 500; break;
    case  Denomination::ZQ_ONE_THOUSAND: Value = 1000; break;
    case  Denomination::ZQ_FIVE_THOUSAND: Value = 5000; break;
    default:
        // Error Case
        Value = 0; break;
    }
    return Value;
}

 Denomination AmountToZero Denomination(CAmount amount)
{
    // Check to make sure amount is an exact integer number of  S
    CAmount residual_amount = amount -   * (amount /  );
    if (residual_amount == 0) {
        return IntToZero Denomination(amount/ );
    } else {
        return  Denomination::ZQ_ERROR;
    }
}

// return the highest denomination that is less than or equal to the amount given
// use case: converting clbi to zclbi without user worrying about denomination math themselves
 Denomination AmountToClosestDenomination(CAmount nAmount, CAmount& nRemaining)
{
    if (nAmount < 1 *  )
        return ZQ_ERROR;

    CAmount nConvert = nAmount /  ;
     Denomination denomination = ZQ_ERROR;
    for (unsigned int i = 0; i < zero DenomList.size(); i++) {
        denomination = zero DenomList[i];

        //exact match
        if (nConvert == denomination) {
            nRemaining = 0;
            return denomination;
        }

        //we are beyond the value, use previous denomination
        if (denomination > nConvert && i) {
             Denomination d = zero DenomList[i - 1];
            nRemaining = nConvert - d;
            return d;
        }
    }
    //last denomination, the highest value possible
    nRemaining = nConvert - denomination;
    return denomination;
}

CAmount Zero DenominationToAmount(const  Denomination& denomination)
{
    CAmount nValue =   * Zero DenominationToInt(denomination);
    return nValue;
}


 Denomination get_denomination(std::string denomAmount) {
    int64_t val = std::stoi(denomAmount);
    return IntToZero Denomination(val);
}


int64_t get_amount(std::string denomAmount) {
    int64_t nAmount = 0;
     Denomination denom = get_denomination(denomAmount);
    if (denom == ZQ_ERROR) {
        // SHOULD WE THROW EXCEPTION or Something?
        nAmount = 0;
    } else {
        nAmount = Zero DenominationToAmount(denom);
    }
    return nAmount;
}

} /* namespace libzero  */
