
#include "functions.hpp"

FUNCTION funcs::MOV(FUNCTION_ARG) {
    // first number is the number of the bits.
    // such as
    // 1 is 1bytes.
    // 2 is 2bytes.
    // 4 is 4bytes.
    // 8 is 8bytes.
    // else thing is error.
    ui8 bytes;
    ui32 location;
    
    bytes = *p;
    p++;
    memcpy(&location, p, 4); // TODO: Replace this with cross-platform it
    p+=4;
    if (!(bytes == 1 || bytes == 2 || bytes == 4 || bytes == 8)) 
        throw std::runtime_error("Try to move noncompliant bytes.");
    for (ui8 i = 0; i < bytes; ++i)
        memory[location + i] = p[i];
}

FUNCTION funcs::ADD(FUNCTION_ARG) {
    // second number is a symbol of the types.
    // such as 0 is i8, 1 is i16, 2 is i32, 3 is i64, 4 is f32, 5 is f64
    // it is base-6 number. such as i8 + i16 is 01 in base-6. it is 1 in base-10. i16 + i32 is 12 in base-6. it is 8 in base-10.
    ui8 types;
    ui32 location1, location2, location3;
    types = *p;
    p++;
    location1 = *reinterpret_cast<const ui32*>(p); // TODO: Replace this with cross-platform it
    p+=4;
    location2 = *reinterpret_cast<const ui32*>(p); // TODO: Replace this with cross-platform it
    p+=4;
    location3 = *reinterpret_cast<const ui32*>(p); // TODO: Replace this with cross-platform it
    p+=4;
    switch (types / 6) { // get the first type
        case 0: // i8
            switch (types % 6) { // get the second type
                case 0: // i8
                    memory[location3] = memory[location1] + memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui16*>(&memory[location3]) = memory[location1] + *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = memory[location1] + *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = memory[location1] + *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] + *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] + *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 1: // i16
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui16*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) + memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui16*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) + *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) + *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) + *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] + *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] + *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 2: // i32
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) + memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) + *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) + *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) + *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] + *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] + *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 3: // i64
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) + memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) + *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) + *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) + *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] + *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] + *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 4: // f32
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) + memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) + *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) + *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) + *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) + *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) + *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 5: // f64
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) + memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) + *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) + *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) + *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) + *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) + *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        default:
            throw std::runtime_error("Try to add noncompliant types.");
    }
}

FUNCTION funcs::SUB(FUNCTION_ARG) {
    // second number is a symbol of the types.
    // such as 0 is i8, 1 is i16, 2 is i32, 3 is i64, 4 is f32, 5 is f64
    // it is base-6 number. such as i8 - i16 is 01 in base-6. it is 1 in base-10. i16 - i32 is 12 in base-6. it is 8 in base-10.
    ui8 types;
    ui32 location1, location2, location3;
    types = *p;
    p++;
    location1 = *reinterpret_cast<const ui32*>(p); // TODO: Replace this with cross-platform it
    p+=4;
    location2 = *reinterpret_cast<const ui32*>(p); // TODO: Replace this with cross-platform it
    p+=4;
    location3 = *reinterpret_cast<const ui32*>(p); // TODO: Replace this with cross-platform it
    p+=4;
    switch (types / 6) { // get the first type
        case 0: // i8
            switch (types % 6) { // get the second type
                case 0: // i8
                    memory[location3] = memory[location1] - memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui16*>(&memory[location3]) = memory[location1] - *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = memory[location1] - *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = memory[location1] - *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] - *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] - *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 1: // i16
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui16*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) - memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui16*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) - *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) - *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) - *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] - *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] - *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 2: // i32
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) - memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) - *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) - *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) - *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] - *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] - *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 3: // i64
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) - memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) - *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) - *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) - *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] - *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] - *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 4: // f32
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) - memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) - *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) - *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) - *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) - *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) - *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 5: // f64
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) - memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) - *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) - *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) - *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) - *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) - *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        default:
            throw std::runtime_error("Try to add noncompliant types.");
    }
}

FUNCTION funcs::MUL(FUNCTION_ARG) {
    ui8 types;
    ui32 location1, location2, location3;
    types = *p;
    p++;
    location1 = *reinterpret_cast<const ui32*>(p);
    p+=4;
    location2 = *reinterpret_cast<const ui32*>(p);
    p+=4;
    location3 = *reinterpret_cast<const ui32*>(p);
    p+=4;
    switch (types / 6) { // get the first type
        case 0: // i8
            switch (types % 6) { // get the second type
                case 0: // i8
                    memory[location3] = memory[location1] * memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui16*>(&memory[location3]) = memory[location1] * *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = memory[location1] * *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = memory[location1] * *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] * *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] * *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 1: // i16
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui16*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) * memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui16*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) * *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) * *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) * *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] * *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] * *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 2: // i32
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) * memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) * *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) * *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) * *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] * *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] * *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 3: // i64
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) * memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) * *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) * *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) * *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] * *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] * *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 4: // f32
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) * memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) * *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) * *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) * *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) * *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) * *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 5: // f64
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) * memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) * *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) * *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) * *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) * *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) * *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        default:
            throw std::runtime_error("Try to add noncompliant types.");
    }
}

FUNCTION funcs::DIV(FUNCTION_ARG) {
    ui8 types;
    ui32 location1, location2, location3;
    types = *p;
    p++;
    location1 = *reinterpret_cast<const ui32*>(p);
    p+=4;
    location2 = *reinterpret_cast<const ui32*>(p);
    p+=4;
    location3 = *reinterpret_cast<const ui32*>(p);
    p+=4;
    switch (types / 6) { // get the first type
        case 0: // i8
            switch (types % 6) { // get the second type
                case 0: // i8
                    memory[location3] = memory[location1] / memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui16*>(&memory[location3]) = memory[location1] / *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = memory[location1] / *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = memory[location1] / *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] / *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] / *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 1: // i16
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui16*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) / memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui16*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) / *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) / *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui16*>(&memory[location1]) / *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] / *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] / *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 2: // i32
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) / memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) / *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui32*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) / *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui32*>(&memory[location1]) / *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] / *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] / *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 3: // i64
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) / memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) / *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) / *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<ui64*>(&memory[location3]) = *reinterpret_cast<ui64*>(&memory[location1]) / *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = memory[location1] / *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = memory[location1] / *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 4: // f32
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) / memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) / *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) / *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) / *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<float*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) / *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<float*>(&memory[location1]) / *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        case 5: // f64
            switch (types % 6) { // get the second type
                case 0: // i8
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) / memory[location2];
                    break;
                case 1: // i16
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) / *reinterpret_cast<ui16*>(&memory[location2]);
                    break;
                case 2: // i32
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) / *reinterpret_cast<ui32*>(&memory[location2]);
                    break;
                case 3: // i64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) / *reinterpret_cast<ui64*>(&memory[location2]);
                    break;
                case 4: // f32
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) / *reinterpret_cast<float*>(&memory[location2]);
                    break;
                case 5: // f64
                    *reinterpret_cast<double*>(&memory[location3]) = *reinterpret_cast<double*>(&memory[location1]) / *reinterpret_cast<double*>(&memory[location2]);
                    break;
                default:
                    throw std::runtime_error("Try to add noncompliant types.");
            }
            break;
        default:
            throw std::runtime_error("Try to add noncompliant types.");
    }
}

// TODO: Use macro to replace them with few code. But I don't have much time to di it, so I will do it later.

std::array<std::function<FuncSig>, 65536> functions;

void functionsInit() {
    functions[VML_mov] = funcs::MOV;
    // Some functions have the same code. So I program them to finish some things about maths.
    functions[VML_add] = funcs::ADD;
    functions[VML_sub] = funcs::SUB;
    functions[VML_mul] = funcs::MUL;
    functions[VML_div] = funcs::DIV;
    // TODO: Add sqrt, qsqrt, log, exp, sin, cos, tan, asin, acos, atan, atan2, pow, abs, floor, ceil, round and so on.

    // TODO: Initialize other functions...
}
