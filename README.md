# LinkedList Init
## Exercise

Create a method to initialize a LinkedList:
The method will return the head node from the LinkedList.

```
struct Node* createList(int size);
```
## Development details

- CMakeLists with the following content:
  - Compiler
  - Folder structure 
  - Setting up unit test cases using googletest
- LinkedList.cpp / LinkedList.hccp
  - createList implementation
- test folder
  - Contains test cases for createList implementation
 
## Set up
I create this project using vscode
### Prerrequisites
- Visual Code with the following plugins
  - [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
  - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
### Tools:
- Googletest
### Installation
- Clone repository (https://github.com/ElenaAlejo/LinkedList.git)
- Open the folder `LinkedList`
- Get Googletest, clonning its repository (https://github.com/google/googletest.git)
- Build project using CMakeTools (reloading the windows/saving will trigger CMakeTools plugin)
- Use command `CMake:Run test` to run test cases
