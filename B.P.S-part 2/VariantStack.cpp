//#include "VariantStack.h"
//
//VariantStack* VariantStack::instance()
//{
//    static VariantStack* varStack = new VariantStack();
//    return varStack;
//}
//
//uint32_t VariantStack::getNewVariantId(VariantType varType)
//{
//    switch (varType)
//    {
//    case VariantType::BOOL:
//    case VariantType::INT:
//        varInteger.insert({ ++idCounter, 0 });
//        break;
//    case VariantType::FLOAT:
//        varDouble.insert({ ++idCounter, 0 });
//        break;
//    case VariantType::STRING:
//        varString.insert({ ++idCounter, ""});
//        break;
//    }
//    return idCounter;
//}
//
//VariantType VariantStack::getVarTypeFromId(uint32_t id)
//{
//    auto res = varBool.find(id);
//    if (res != varBool.end()) return VariantType::BOOL;
//
//    return VariantType();
//}
//
//auto VariantStack::getVariantFromId(uint32_t id)
//{
//
//}
