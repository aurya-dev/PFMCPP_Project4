/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) make sure it compiles & runs without errors.
 
 7) use your knowledge of casting to remove any conversion warnings. 

 8) insert 'part3();' before the 'good to go' at the end of your main(); 
        move this part3 function to before main()

 9) click the [run] button.  Clear up any errors or warnings as best you can.

 */

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^3 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( it ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( pi ).multiply( dt ).subtract( ft ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( ft ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( dt ).add( ft ).multiply( 24 ) << std::endl;
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 

FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^3 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
good to go!




*/

#include <iostream>

struct FloatType;
struct IntType;
struct DoubleType;

//-------------------------------------------------
// FloatType
//-------------------------------------------------

struct FloatType
{
    float* value;

    FloatType(float f) : value (new float{f}) {}
    ~FloatType()
    {
        delete value;
        value = nullptr;
    }

    FloatType& add(float f );
    FloatType& add(const DoubleType& d );
    FloatType& add(const IntType& i);

    FloatType& subtract(float f );
    FloatType& subtract(const DoubleType& d );
    FloatType& subtract(const IntType& i);
    
    FloatType& multiply(float rhs );
    FloatType& multiply(const DoubleType& d );
    FloatType& multiply(const IntType& i);
    
    FloatType& divide(float rhs );
    FloatType& divide(const DoubleType& d );
    FloatType& divide(const IntType& i);
};

//-------------------------------------------------
// DoubleType
//-------------------------------------------------

struct DoubleType
{
    double* value;

    DoubleType(double d) : value (new double{d}) {}
    ~DoubleType()
    {
        delete value;
        value = nullptr;
    }

    DoubleType& add(double d );
    DoubleType& add(const FloatType& f);
    DoubleType& add(const IntType& f);

    DoubleType& subtract(double d );
    DoubleType& subtract(const FloatType& f);
    DoubleType& subtract(const IntType& i);

    DoubleType& multiply(double d );
    DoubleType& multiply(const FloatType& f);
    DoubleType& multiply(const IntType& i);
    
    DoubleType& divide(double d );
    DoubleType& divide(const FloatType& f);
    DoubleType& divide(const IntType& i);
};


//-------------------------------------------------
// IntType
//-------------------------------------------------

struct IntType
{
    int* value;

    IntType(int i) : value(new int{i}) {}
    ~IntType()
    {
        delete value;
        value = nullptr;
    }

    IntType& add(int i );
    IntType& add(const FloatType& f );
    IntType& add(const DoubleType& d );

    IntType& subtract(int i );
    IntType& subtract(const FloatType& f );
    IntType& subtract(const DoubleType& d );

    IntType& multiply(int i );
    IntType& multiply(const FloatType& f );
    IntType& multiply(const DoubleType& d );

    IntType& divide(int i );
    IntType& divide(const FloatType& f );
    IntType& divide(const DoubleType& d );

};



//-------------------------------------------------
// add
//-------------------------------------------------

FloatType& FloatType::add(float f )
{
    *value += f;
    return *this;
}

FloatType& FloatType::add(const DoubleType& dt )
{
    return add(*dt.value);
}

FloatType& FloatType::add(const IntType& it)
{
    return add(*it.value);
}

//-------------------------------------------------

DoubleType& DoubleType::add(double d )
{
    *value += d;
    return *this;
}

DoubleType& DoubleType::add(const FloatType& ft)
{
    return add(*ft.value);
}

DoubleType& DoubleType::add(const IntType& it)
{
    return add(*it.value);
}

//-------------------------------------------------

IntType& IntType::add(int i )
{
    *value += i;
    return *this;
}

IntType& IntType::add(const DoubleType& dt )
{
    return add(*dt.value);
}

IntType& IntType::add(const FloatType& ft)
{
    return add(*ft.value);
}

//-------------------------------------------------
// subtract
//-------------------------------------------------

FloatType& FloatType::subtract(float f )
{
    *value -= f;
    return *this;
}

FloatType& FloatType::subtract(const DoubleType& dt )
{
    return subtract(*dt.value);
}

FloatType& FloatType::subtract(const IntType& it)
{
    return subtract(*it.value);
}


//-------------------------------------------------

DoubleType& DoubleType::subtract(double d )
{
    *value -= d;
    return *this;
}

DoubleType& DoubleType::subtract(const FloatType& ft )
{
    return subtract(*ft.value);
}

DoubleType& DoubleType::subtract(const IntType& it )
{
    return subtract(*it.value);
}

//-------------------------------------------------

IntType& IntType::subtract(int i )
{
    *value -= i;
    return *this;
}

IntType& IntType::subtract(const FloatType& ft )
{
    return subtract(*ft.value);
}

IntType& IntType::subtract(const DoubleType& dt )
{
    return subtract(*dt.value);
}


//-------------------------------------------------
// multiply
//-------------------------------------------------

FloatType& FloatType::multiply(float f )
{
    *value *= f;
    return *this;
}

FloatType& FloatType::multiply(const IntType& it)
{
    return multiply(*it.value);
}

FloatType& FloatType::multiply(const DoubleType& dt )
{
    return multiply(*dt.value);
}

//-------------------------------------------------

DoubleType& DoubleType::multiply(double d )
{
    *value *= d;
    return *this;
}

DoubleType& DoubleType::multiply(const FloatType& ft )
{
    return multiply(*ft.value);
}

DoubleType& DoubleType::multiply(const IntType& it)
{
    return multiply(*it.value);
}

//-------------------------------------------------

IntType& IntType::multiply(int i )
{
    *value *= i;
    return *this;
}

IntType& IntType::multiply(const DoubleType& dt )
{
    return multiply(*dt.value);
}

IntType& IntType::multiply(const FloatType& ft)
{
    return multiply(*ft.value);
}


//-------------------------------------------------
// divide
//-------------------------------------------------

FloatType& FloatType::divide(float f )
{
    if(f == 0.0f)
        std::cout << "warning: floating point division by zero!" << std::endl;
    *value /= f;
    return *this;
}

FloatType& FloatType::divide(const IntType& it)
{
    if(*it.value == 0)
        std::cout << "warning: floating point division by zero!" << std::endl;
    return divide(*it.value);
}

FloatType& FloatType::divide(const DoubleType& dt )
{
    if(*dt.value == 0.0)
        std::cout << "warning: floating point division by zero!" << std::endl;
    return divide(*dt.value);
}

    
//-------------------------------------------------

DoubleType& DoubleType::divide(double d )
{
    if(d == 0.0)
        std::cout << "warning: floating point division by zero!" << std::endl;
    *value /= d;
    return *this;
}

DoubleType& DoubleType::divide(const IntType& it)
{
    if(*it.value == 0)
        std::cout << "warning: floating point division by zero!" << std::endl;
    return divide(*it.value);
}

DoubleType& DoubleType::divide(const FloatType& ft )
{
    if(*ft.value == 0.0f)
        std::cout << "warning: floating point division by zero!" << std::endl;
    return divide(*ft.value);
}

//-------------------------------------------------

IntType& IntType::divide(int i)
{
    if(i == 0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl;
        return *this;
    }
    *value /= i;
    return *this;
}

IntType& IntType::divide(const DoubleType& dt)
{
    if(*dt.value == 0.0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl;
        divide(*dt.value);
    }
    return divide(*dt.value);
}

IntType& IntType::divide(const FloatType& ft )
{
    if(*ft.value == 0.0f)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl;
        divide(*ft.value);
    }
    return divide(*ft.value);
}
   






int main()
{
    //testing instruction 0
    HeapA heapA;

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << *ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << *ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << *ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << *ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << *dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << *dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << *dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << *dt.divide(5.0).value << std::endl << std::endl;

    std::cout << "IntType add result=" << *it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << *it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << *it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << *it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << *(it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

    // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << *ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl;
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << *dt.value << std::endl;
    std::cout << "Initial value of it: " << *it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << *dt.multiply(it).divide(5.0f).add(ft).value << std::endl;

    std::cout << "---------------------\n" << std::endl;
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << *it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << *ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << *dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl;

    std::cout << "good to go!\n";

    return 0;
}



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */



  /*


#include <iostream>
int main()
{
    FloatType ft;
    std::cout << "result of ft.add(): " << ft.add( 123.456f, 432.1f) << std::endl;
    std::cout << "result of ft.subtract(): " << ft.subtract( 123.456f, 432.1f) << std::endl;
    std::cout << "result of ft.multiply(): " << ft.multiply( 123.456f, 432.1f) << std::endl;
    std::cout << "result of ft.divide(): " << ft.divide( 123.456f, 432.1f) << std::endl;

    std::cout << "result of ft.add(): " << ft.add( 4444.56f, 0.0f)  << std::endl;
    std::cout << "result of ft.subtract(): " << ft.subtract( 4444.56f, 0.0f) << std::endl;
    std::cout << "result of ft.multiply(): " << ft.multiply( 4444.56f, 0.0f) << std::endl;
    std::cout << "result of ft.divide(): " << ft.divide( 4444.56f, 0.0f) << std::endl;

    DoubleType db;
    std::cout << "result of db.add(): " << db.add( 123.456, 432.1) << std::endl;
    std::cout << "result of db.subtract(): " << db.subtract( 123.456, 432.1) << std::endl;
    std::cout << "result of db.multiply(): " << db.multiply( 123.456, 432.1) << std::endl;
    std::cout << "result of db.divide(): " << db.divide( 123.456, 432.1) << std::endl;

    std::cout << "result of db.add(): " << db.add( 123.456, 0.0) << std::endl;
    std::cout << "result of db.subtract(): " << db.subtract( 123.456, 0.0) << std::endl;
    std::cout << "result of db.multiply(): " << db.multiply( 123.456, 0.0) << std::endl;
    std::cout << "result of db.divide(): " << db.divide( 123.456, 0.0) << std::endl;

    IntType i;
    std::cout << "result of i.add(): " << i.add( 10, 20) << std::endl;
    std::cout << "result of i.subtract(): " << i.subtract( 10, 20) << std::endl;
    std::cout << "result of i.multiply(): " << i.multiply( 10, 20) << std::endl;
    std::cout << "result of i.divide(): " << i.divide( 10, 20) << std::endl;

    std::cout << "result of i.add(): " << i.add( 10, 0) << std::endl;
    std::cout << "result of i.subtract(): " << i.subtract( 10, 0) << std::endl;
    std::cout << "result of i.multiply(): " << i.multiply( 10, 0) << std::endl;
    std::cout << "result of i.divide(): " << i.divide( 10, 0) << std::endl;

    std::cout << "good to go!" << std::endl;
}

*/


