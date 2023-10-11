# Conceptual Understanding

## compiler warnings
### DO NOT IGNORE THEM
- the compiler has recognized an issue with your code that could lead to a potential problem
- it's only a warning because the compiler is still able to generate correct machine code

- example below will show unexpected number. 
```cpp
int main()
{
    int favorite_number;
    std::cout << favorite_number << std::endl;
    return 0;
    /* syntactically nothing wrong but you will get error favorite_number is used uninitialized in this function */
}
```

## LINKER ERRORS
### The linker is having trouble linking all the object files together to create an executable
### usually there is a library or object file that is missing

## scope and global variables
