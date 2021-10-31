#include <iostream>
#include "BInarySearchTree.h"
using namespace std;
int main(){
   BST b1;
   b1.insert(10);
   b1.insert(5);
   b1.insert(20);
   b1.insert(7);
   b1.insert(3);
   b1.insert(15);
   b1.printLevelWise();
   b1.deleteData(10);
   b1.printLevelWise();
   return 0;
}