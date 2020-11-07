//301346228, sclousto, Sage Clouston
/*
**  a4.cpp
**  Assignment 4, CMPT-225
**
**  Reads a sequence of integers (in the range of int's) from standard in;
**  It is interpreted as two lists, separated by a single 0
**/
#include <iostream>
//C++ queue stl NOT BY ME
#include <queue>
//NOT BY ME
#include <fstream>

using namespace std;

int main(){
	
	//variable for file
	ifstream file;

	//two queues to store the values from the file
	priority_queue <int> q1;
	priority_queue <int> q2;

	//boolean to prevent the algorithm from running if initial conditions are not met
	bool run = true;
	
	file.open("sample1.txt");

	//if there is an error reading the file exit program
	if(!file) {
	  cout << "file error";
	  return 1;
	}
	
     int x ;
     bool List2 = false; 

     while( file >> x ){
        if( x == 0 ){
            List2 = true ;
        }
	
	//input the second list into q2
	if(List2 == true && x != 0) {
	  q2.push(x);
	}
	//input the first list into q1
	else if(x != 0) {
	  q1.push(x);
	}
     }

     file.close();

	//two max file to store the current max of each list
	int max1 = -1;
	int max2 = -1;

	//if q1 is empty don't run the algorithm, else set max1 to the first element of q1
	if(q1.empty()) {
	  run = false;
	}
	else {
	  max1 = q1.top();
	}
	//if q2 is empty don't run the algorithm, else set max2 to the first element of q2
	if(q2.empty()) {
	  run = false;
	}
	else {
	  max2 = q2.top();
	}

	//main algorithm
	while(run) {
	  //if max1 equals max2 get the next element from q1
	  if(max1 == max2) {
	    q1.pop();
	    //if q1 is empty set max1 to -1 and break from the algorithm
	    if(q1.empty()) {
	      max1 = -1;
	      break;
	    }
	    max1 = q1.top();
	  }
	  //if max1 doesn't equal max2 get the next element from q2
	  else {
  	    q2.pop();
	    //if q2 is empty break from the algorithm
	    if(q2.empty() || max2 < max1) {
	      break;
	    }
	    max2 = q2.top(); 
	  }
	}

	cout << "301346228 sclousto Sage Clouston" << endl;

	//if max1 is -1 then there is no max in L1 that isn't in L2
	if(max1 == -1) {
	  cout << "NONE";
	}
	//output the max in L1 that isn't in L2
	else{
	  cout << max1 << endl;
	}

	return 0;
}
