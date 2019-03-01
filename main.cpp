#include <iostream>
#include <iomanip>
#include <cmath>
#include "vector3.h"

/**
 * Test cases for vector3.cpp
 * ECE2036 Lab 3
 * Jackson McMath jmcmath@gatech.edu
 * 
 * This file tests the following implementations in vector3.cpp:
 *   - Constructors
 *   - Getters
 *   - Setters
 *   - Equality
 *   - Inequality
 *   - Operator+ (Vector3)
 *   - Operator- (Vector3)
 *   - Operator* (Vector3)
 *   - Operator/ (Vector3)
 *   - Operator+ (int)
 *   - Operator- (int)
 *   - Operator* (int)
 *   - Operator/ (int)
 *   - Operator+= (Vector3)
 *   - Operator-= (Vector3)
 *   - Operator*= (Vector3)
 *   - Operator/= (Vector3)
 *   - Dot Product
 *   - Cross Product
 *   - Rotate Left (prefix)
 *   - Rotate Left (postfix)
 *   - Rotate Right (prefix)
 *   - Rotate Right (postfix)
 *   - Length
 *   - Operator+ (global int)
 *   - Operator* (global int)
 *   - Operator<<
 * 
 * Some tests require other tests to pass in order to function properly. For
 * example, the constructor tests require that getters be working properly. This
 * might cause some weird behavior.
 * 
 * DISCLAIMER: These test cases do not guarantee anything. Just because you pass
 *             all or most of the test cases does not mean you will get a good
 *             grade. You should always thoroughly test your own code yourself.
 */
int main()
{
    // some formatting for printing
    using std::cout;
    using std::setw;
    cout << std::left;
    cout << std::setfill('.');

    bool results[15];

    // test constructors
    cout << setw(30) << "Constructor:";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(69);
        Vector3 v3 = Vector3(4, 2, 0);
        if ((v1.get_x() == 0 && v1.get_y() == 0 && v1.get_z() == 0) && (v2.get_x() == 69 && v2.get_y() == 69 && v2.get_z() == 69) && (v3.get_x() == 4 && v3.get_y() == 2 && v3.get_z() == 0))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (v1.get_x() != 0 || v1.get_y() != 0 || v1.get_z() != 0)
                cout << "\"Vector3::Vector3()\" does not correctly initialize \"Vector3::x\", \"Vector3::y\" or \"Vector3::z\" to zero (0)\n";
            if (v2.get_x() != 69 || v2.get_y() != 69 || v2.get_z() != 69)
                cout << "\"Vector3::Vector3(int)\" does not correctly initialize \"Vector3::x\", \"Vector3::y\" or \"Vector3::z\" to \"int\"\n";
            if (v3.get_x() != 4 || v3.get_y() != 2 || v3.get_z() != 0)
                cout << "\"Vector3::Vector3(int, int, int)\" does not correctly initialize \"Vector3::x\", \"Vector3::y\" or \"Vector3::z\"\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test getters
    cout << setw(30) << "Getter:";
    try
    {
        Vector3 v1 = Vector3(1, 2, 3);
        int x = v1.get_x(), y = v1.get_y(), z = v1.get_z();
        if (x == 1 && y == 2 && z == 3)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (x != 1)
                cout << "\"Vector3::get_x(int)\" does not correctly get \"Vector3::x\"\n";
            if (y != 2)
                cout << "\"Vector3::get_y(int)\" does not correctly get \"Vector3::y\"\n";
            if (z != 3)
                cout << "\"Vector3::get_z(int)\" does not correctly get \"Vector3::z\"\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test setters
    cout << setw(30) << "Setter:";
    try
    {
        Vector3 v1 = Vector3(1, 2, 3);
        v1.set_x(3); v1.set_y(4); v1.set_z(5);
        int x = v1.get_x(), y = v1.get_y(), z = v1.get_z();
        if (x == 3 && y == 4 && z == 5)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (x != 3)
                cout << "\"Vector3::set_x(int)\" does not correctly set \"Vector3::x\"\n";
            if (y != 4)
                cout << "\"Vector3::set_y(int)\" does not correctly set \"Vector3::y\"\n";
            if (z != 5)
                cout << "\"Vector3::set_z(int)\" does not correctly set \"Vector3::z\"\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test equality
    cout << setw(30) << "Equality:";
    try
    {
        Vector3 v1 = Vector3(1, 2, 3);
        Vector3 v2 = Vector3(1, 2, 3);

        if (v1 == v1 && v1 == v2)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator==(Vector3 const&)\" does not correctly check component-wise equality\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    // test inequality
    cout << setw(30) << "Inequality:";
    try
    {
        Vector3 v1 = Vector3(1, 2, 3);
        Vector3 v2 = Vector3(7, 8, 9);

        if (v1 != v2)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator!=(Vector3 const&)\" does not correctly check component-wise inequality\n";
        }
        
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    
    // test operator+ (Vector3)
    cout << setw(30) << "Operator+ (Vector3):";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(2);
        Vector3 v3 = Vector3(3, 4, 5);

        if (v1 + v2 == Vector3(2,2,2) && v3 + v2 + v1 == Vector3(5,6,7))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator+(Vector3 const&)\" does not correctly implement component-wise addition\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator- (Vector3)
    cout << setw(30) << "Operator- (Vector3):";
    try
    {
        Vector3 v1 = Vector3(2);
        Vector3 v2 = Vector3(3, 4, 5);

        if (v2 - v1 == Vector3(1,2,3) && v2 - v1 - v1 == Vector3(-1,0,1))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator-(Vector3 const&)\" does not correctly implement component-wise subtraction\n";
        }
        
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    // test operator* (Vector3)
    cout << setw(30) << "Operator* (Vector3):";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(2);
        Vector3 v3 = Vector3(3, 4, 5);

        if (v1 * v3 == Vector3() && v3 * v2 * v3 == Vector3(18,32,50))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator*(Vector3 const&)\" does not correctly implement component-wise multiplication\n";
        }
        
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    // test operator/ (Vector3)
    cout << setw(30) << "Operator/ (Vector3):";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(2);
        Vector3 v3 = Vector3(3, 4, 5);

        if (v1 / v2 == Vector3() && v3 / v2 == Vector3(1,2,2) && v3 / v2 / v2 == Vector3(0,1,1))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator/(Vector3 const&)\" does not correctly implement component-wise division\n";
        }
        
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator+ (int)
    cout << setw(30) << "Operator+ (int):";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(3, 4, 5);

        if (v1 + 5 == Vector3(5) && v2 + 2 + 1 == Vector3(6,7,8))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator+(int)\" does not correctly implement component-wise addition\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator- (int)
    cout << setw(30) << "Operator- (int):";
    try
    {
        Vector3 v1 = Vector3(2);
        Vector3 v2 = Vector3(3, 4, 5);

        if (v1 - 3 == Vector3(-1) && v2 - 2 - 1 == Vector3(0,1,2))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator-(int)\" does not correctly implement component-wise subtraction\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator* (int)
    cout << setw(30) << "Operator* (int):";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(2);
        Vector3 v3 = Vector3(3, 4, 5);

        if (v1 * 4 == Vector3() && v2 * 2 * 2 == Vector3(8))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator*(int)\" does not correctly implement component-wise multiplication\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator/ (int)
    cout << setw(30) << "Operator/ (int):";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(2);
        Vector3 v3 = Vector3(3, 4, 5);

        if (v1 / 2 == Vector3() && v2 / 2 / 1 == Vector3(1))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator/(int)\" does not correctly implement component-wise division\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator+= (Vector3)
    cout << setw(30) << "Operator+= (Vector3):";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(2);
        Vector3 v3 = Vector3(3, 4, 5);
        Vector3 *pv1 = &v1;

        v1 += v2; // [0, 0, 0] + [2, 2, 2] = [2, 2, 2]
        v2 += v3; // [2, 2, 2] + [3, 4, 5] = [5, 6, 7]
        v3 += v1; // [3, 4, 5] + [2, 2, 2] = [5, 6, 7]

        if (v1 == Vector3(2) && v2 == Vector3(5,6,7) && v3 == Vector3(5,6,7) && pv1 == &v1)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (pv1 != &v1)
                cout << "\"Vector3::operator+=(Vector3 const&)\" does not return the original Vector3 instance\n";
            cout << "\"Vector3::operator+=(Vector3 const&)\" does not correctly implement component-wise add-equals\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator-= (Vector3)
    cout << setw(30) << "Operator-= (Vector3):";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(2);
        Vector3 v3 = Vector3(3, 4, 5);
        Vector3 *pv1 = &v1;

        v1 -= v2; // [0, 0, 0] - [ 2,  2,  2] = [-2, -2, -2]
        v2 -= v3; // [2, 2, 2] - [ 3,  4,  5] = [-1, -2, -3]
        v3 -= v1; // [3, 4, 5] - [-2, -2, -2] = [ 5,  6,  7]

        if (v1 == Vector3(-2) && v2 == Vector3(-1,-2,-3) && v3 == Vector3(5,6,7) && pv1 == &v1)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (pv1 != &v1)
                cout << "\"Vector3::operator-=(Vector3 const&)\" does not return the original Vector3 instance\n";
            cout << "\"Vector3::operator-=(Vector3 const&)\" does not correctly implement component-wise subtract-equals\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator*= (Vector3)
    cout << setw(30) << "Operator*= (Vector3):";
    try
    {
        Vector3 v1;
        Vector3 v2 = Vector3(2);
        Vector3 v3 = Vector3(3, 4, 5);
        Vector3 *pv1 = &v1;

        v1 *= v2; // [0, 0, 0] * [2, 2, 2] = [0, 0, 0]
        v2 *= v3; // [2, 2, 2] * [3, 4, 5] = [6, 8, 10]
        v3 *= v1; // [3, 4, 5] * [0, 0, 0] = [0, 0, 0]

        if (v1 == Vector3() && v2 == Vector3(6,8,10) && v3 == Vector3() && pv1 == &v1)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (pv1 != &v1)
                cout << "\"Vector3::operator*=(Vector3 const&)\" does not return the original Vector3 instance\n";
            cout << "\"Vector3::operator*=(Vector3 const&)\" does not correctly implement component-wise multiply-equals\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator/= (Vector3)
    cout << setw(30) << "Operator/= (Vector3):";
    try
    {
        Vector3 v1 = Vector3(4);
        Vector3 v2 = Vector3(2);
        Vector3 v3 = Vector3(3, 4, 5);
        Vector3 *pv1 = &v1;

        v1 /= v2; // [4, 4, 4] / [2, 2, 2] = [2, 2, 2]
        v2 /= v3; // [2, 2, 2] / [3, 4, 5] = [0, 0, 0]
        v3 /= v1; // [3, 4, 5] / [2, 2, 2] = [1, 2, 2]

        if (v1 == Vector3(2) && v2 == Vector3() && v3 == Vector3(1,2,2) && pv1 == &v1)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (pv1 != &v1)
                cout << "\"Vector3::operator/=(Vector3 const&)\" does not return the original Vector3 instance\n";
            cout << "\"Vector3::operator/=(Vector3 const&)\" does not correctly implement component-wise divide-equals\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    // test dot product
    cout << setw(30) << "Dot Product:";
    try
    {
        Vector3 v1 = Vector3(2);
        Vector3 v2 = Vector3(1, 2, 3);
        Vector3 v3 = Vector3(6, 7, 8);

        if ((v2 | v3) == 44.0 && (v1 | v2) == 12.0)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator|(Vector3 const&)\" does not correctly implement dot product\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test cross product
    cout << setw(30) << "Cross Product:";
    try
    {
        Vector3 v1 = Vector3(3, -3, 1);
        Vector3 v2 = Vector3(4, 9, 2);
        Vector3 v3 = Vector3(-12, 12, -4);

        if ((v1 ^ v2) == Vector3(-15,-2,39) && (v1 ^ v3) == Vector3())
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::operator^(Vector3 const&)\" does not correctly implement cross product\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test rotate left (prefix)
    cout << setw(30) << "Rotate Left (prefix):";
    try
    {
        Vector3 v1 = Vector3(1, 2, 3);
        Vector3 *pv1 = &v1;

        if (++v1 == Vector3(2,3,1) && pv1 == &v1)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (pv1 != &v1)
                cout << "\"Vector3::operator++()\" does not return the original Vector3 instance\n";
            cout << "\"Vector3::operator++()\" does not correctly implement rotate left (prefix)\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test rotate left (postfix)
    cout << setw(30) << "Rotate Left (postfix):";
    try
    {
        Vector3 v1 = Vector3(1, 2, 3);
        Vector3 *pv1 = &v1;

        if (v1++ == Vector3(1,2,3) && v1 == Vector3(2,3,1) && pv1 == &v1)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (pv1 != &v1)
                cout << "\"Vector3::operator++(int)\" does not return the original Vector3 instance\n";
            cout << "\"Vector3::operator++(int)\" does not correctly implement rotate left (postfix)\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test rotate Right (prefix)
    cout << setw(30) << "Rotate Right (prefix):";
    try
    {
        Vector3 v1 = Vector3(1, 2, 3);
        Vector3 *pv1 = &v1;

        if (--v1 == Vector3(3,1,2) && pv1 == &v1)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (pv1 != &v1)
                cout << "\"Vector3::operator--()\" does not return the original Vector3 instance\n";
            cout << "\"Vector3::operator--()\" does not correctly implement rotate right (prefix)\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test rotate right (postfix)
    cout << setw(30) << "Rotate Reft (postfix):";
    try
    {
        Vector3 v1 = Vector3(1, 2, 3);
        Vector3 *pv1 = &v1;

        if (v1-- == Vector3(1,2,3) && v1 == Vector3(3,1,2) && pv1 == &v1)
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            if (pv1 != &v1)
                cout << "\"Vector3::operator--(int)\" does not return the original Vector3 instance\n";
            cout << "\"Vector3::operator--(int)\" does not correctly implement rotate right (postfix)\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test length
    cout << setw(30) << "Length:";
    try
    {
        Vector3 v1 = Vector3(2);
        Vector3 v2 = Vector3(1, 2, 3);
        Vector3 v3 = Vector3(-4, -2, -1);

        if (v1.length() == sqrt(12) && v2.length() == sqrt(14) && v3.length() == sqrt(21))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"Vector3::length()\" does not correctly return the magnitude\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
        return 1;
    }

    // test operator+ (global int)
    cout << setw(30) << "Operator+ (global int):";
    try
    {
        Vector3 v1 = Vector3(4);
        Vector3 v2 = Vector3(1, 2, 3);

        if (3 + v1 == Vector3(7) && 4 + v2 == Vector3(5,6,7))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"operator+(int, Vector3 const&)\" does not correctly implement component-wise addition\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
    }
    
    // test operator* (global int)
    cout << setw(30) << "Operator* (global int):";
    try
    {
        Vector3 v1 = Vector3(2);
        Vector3 v2 = Vector3(1, 2, 3);

        if (4 * v1 == Vector3(8) && 2 * v2 == Vector3(2,4,6))
            cout << "\033[32mPass\033[0m\n";
        else
        {
            cout << "\033[31mFail\033[0m\n";
            cout << "\"operator*(int, Vector3 const&)\" does not correctly implement component-wise multiplication\n";
        }
    }
    catch(const std::exception& e)
    {
        cout << "\033[31mFail\033[0m\n";
        std::cerr << e.what() << '\n';
    }
    
    cout << std::endl;
    return 0;
}