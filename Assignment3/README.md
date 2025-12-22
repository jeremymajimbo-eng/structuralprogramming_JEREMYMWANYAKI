NUMBER ONE
Difference Between a Normal Variable and a Pointer
 Normal Variable
 -Stores an actual data value (e.g., an integer).
 -Memory is accessed directly using the variable name.
 -Values are read and modified directly.
 Pointer
 -Stores the memory address of another variable.
 -Memory is accessed indirectly using dereferencing (*).
 -Values are read and modified through the address.
| Feature        | Normal Variable   | Pointer                    |
| -------------- | ----------------- | -------------------------- |
| What it stores | Actual value      | Address of a variable      |
| Access method  | Direct            | Indirect (dereferencing)   |
| Modification   | Direct assignment | Using `*` operator         |
| Memory access  | Own memory        | Memory of another variable |

NUMBER TWO
2. Variable Declaration vs Pointer Declaration and Definition
Variable Declaration & Definition
 -x holds an integer value.
 -No special operators are required.
Pointer Declaration & Definition
 Role of Operators
  & (Address-of operator):
   -Used to obtain the address of a variable.
  * (Indirection / Dereference operator):
   -Used to declare a pointer or access the value at an address.

NUMBER THREE
3. Dereferencing a Pointer
Meaning of Dereferencing
 -Dereferencing means accessing or modifying the value stored at the memory address held by a pointer using the * operator.
Explanation
 -ptr → stores address of num
 -*ptr → accesses the value at that address
 -Changing *ptr directly changes num

NUMBER FOUR
4. Scenarios Where Pointers Are Preferred Over Normal Variables
 Scenario 1: Modifying Values Inside Functions
  -Pointers allow pass by reference, enabling functions to change original variables.
 Scenario 2: Dynamic Memory Allocation
  -Pointers are essential for managing memory at runtime.
 Other Use Cases
  -Working with arrays and strings
  -Building data structures (linked lists, trees)
  -Improving performance by avoiding copying large data

NUMBER FIVE
 5. Limitations and Risks of Using Pointers
   Risks
   -Dangling pointers: pointing to freed memory
   -Null pointer dereferencing: causes runtime crashes
   -Memory leaks: forgetting to free allocated memory
   -Complex code: harder to read and debug
  | Aspect     | Variables | Pointers         |
  | ---------- | --------- | ---------------- |
  | Safety     | Safer     | Risky if misused |
  | Complexity | Simple    | More complex     |
  | Control    | Limited   | Very powerful    |
  
NUMBER SIX
 6. Call by Value vs Call by Reference
    Call by Value
    -A copy of the variable is passed.
    -Original value is not modified.
    Call by Reference
    -Address of the variable is passed.
    -Original value can be modified
  | Feature           | Call by Value | Call by Reference |
  | ----------------- | ------------- | ----------------- |
  | Data passed       | Copy of value | Address           |
  | Uses pointers     | No            | Yes               |
  | Original data     | Unchanged     | Modified          |
  | Memory efficiency | Lower         | Higher            |

NUMBER SEVEN
 7. Practical Scenarios
 a) When Call by Value Is Preferred
    -When original data must remain unchanged
    -For small data types (int, char)
    -When safety and simplicity are important
   Example:
   -Mathematical calculations
   -Validation functions
 b) When Call by Reference Is Preferred
    -When function must modify original data
    -When passing large data structures
    -For better performance
   Example:
   -Swapping values
   -Updating arrays
   -File handling and buffers


