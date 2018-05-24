


// resize
void ourStr::resize(int newSize){
  if(newSize< len)
    newSize=len;
  if(newSize < 1)
    newSize=1;



}

// Deep Copy
Object& ourStr::operator=(const &ourStr rhs){

  if(this != &rhs){
   // dynamically allocate new char array
    char *newData = new char[rhs.capacity];

   // copy data from old array to new one
    for(int i =0; i<rhs.len; i++)
      newData[i] = data[i];

   // delete old array
    delete [] data;

   // assign pointer from data to newData
    data=newData;

   // assign capacity and member variables
    capacity=rhs.capacity;
    len = rhs.len;
  }
   return *this;
}


// Copy Constructor
// either commented section or for loop will produce a copy.
  ourStr::ourStr(const ourStr &src) : capacity(src.capacity), len(src.len)
  {
   for(i=0; i<len; i++)
     data[i] = src.data[i];

  }
