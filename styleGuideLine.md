# Style Guideline

> [!NOTE]
> The primary goal is to explain concepts rather than focusing on implementation details. Therefore, we aren't using setters and getters to access class data members. This approach keeps the code concise and directs attention to the core ideas being discussed.

<br/>

- Class name should be written in Pascal Case

   ```cpp
   class LinkedList
   ```

----

- for class or function templates, use the `typename` keyword instead of `class` keyword

   Do: 
    ```cpp
    template <typename T> ..
    ```
   
    Don't: 
    ```cpp
    template <class T> ..
   ```

----

- functions and variable names should be written in camelCase
- consider using `const`  whenever applicable especially for member functions that don't modify the object

  ```cpp
  void isEmpty() const;
  int newData;
  ```

----

- Clearly separate type name from variable name, pointer () and reference (&) type designators are to be placed next to the type name without any whitespace. Variable names should be then placed after a whitespace. ()

  Do:
  
  ```cpp
  int* ptr;
  int& value;
  ```
  
  Don't 
  ```cpp
  int *ptr;
  int &value;
  ```

-----

- Pointers' names should end with ptr to make it clear

  ```cpp
  Node* headPtr;
  Node* frontPtr;
  ```

-----

- opening braces should be placed on a new line

  Do:
  
  ```cpp
  function
  {
    //function body
  }
  ```
  
  Don't
  
  ```cpp
  function{
  	//function body
  }
  ```

----

- Use of `nullptr` is preferred over `NULL` to adhere to modern C++ practices
- Avoid `using namespace std` 
