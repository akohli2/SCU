
#include "dynamicbag.h"

    // CONSTRUCTORS

    // pre: none
    // post: creates an initially empty DynamicBag
    DynamicBag::DynamicBag(){
      used_ = 0;
      capacity_ = 0;
      data_ = nullptr;
    }

    // copy constructor  (NEW! Before we used the built-in one)
    //e.g:  DynamicBag b2 = b1; OR DynamicBag b2(b1);
    // pre: none
    // post: creates a new DynamicBag which is a copy of the given one
    DynamicBag::DynamicBag(const DynamicBag &b){
      used_ = b.used_;
      capacity_ = b.capacity_;
      data_ = new int[capacity_];
      for(size_type i = 0; i<used_; ++i){
        data_[i] = b[i];
      }
    }
/*  This is what the built-in copy constructor (shallow copy) does.  Problem??
    DynamicBag::DynamicBag(const DynamicBag &b){
      used_ = b.used_;
      capacity_ = b.capacity_;
      data_ = b.data_;
    }
*/
    // pre: none  (NEW!  Before we used the built-in one)
    // post: makes this bag a copy of b
    void DynamicBag::operator =(const DynamicBag &b){
      //this is a _pointer_ to the object you're inside of
      if(this==&b){
        return;//this.count(5);NO!!!!!!!!!!!!!!!!!!
      }//   (*this).count(5);  OR this->count();
      else{
        used_ = b.used_;
        capacity_ = b.capacity_;
        delete [] data_;
        data_ = new int[capacity_];//if = was called by b=b, what is the problem here?
        for(size_type i = 0; i<used_; ++i){//Values in the old array are lost!
          data_[i] = b[i];
        }
      }
    }


    // pre: none    (NEW!  Our first destructor)
    // post: destroys this DynamicBag; needed because we are using
    //       dynamically allocated memory
    //Called automatically by C++ when an object ceases to exist
    DynamicBag::~DynamicBag(){
        delete [] data_;//This is all you NEED
        data_ = nullptr;
        capacity_ = 0;
        used_ = 0;
    }

    //pre:  pos<capacity_
    //post:  returns the pos(th) item in the bag.
    int DynamicBag::operator [](size_type pos) const{
      assert(pos<capacity_);
      return data_[pos];
    }

    // pre: none
    // post: if target appears in this DynamicBag, returns the number of times it appears
    //       else, returns 0
    //typename:  promises C++ that DynamicBag::size_type is a type
    typename DynamicBag::size_type DynamicBag::count(int target) const{
      size_type count = 0;
      for(size_type i = 0; i<used_; ++i){
        if(data_[i]==target)
          ++count;
      }
      return count;
    }


    // MODIFICATION (MUTATOR) MEMBER FUNCTIONS

    // pre: none
    // post: adds a copy of target to this DynamicBag
    void DynamicBag::insert(int target){
      if(used_>=capacity_){//== is fine
        int newsize = 0;
        if(capacity_ ==0)
          newsize = 1;
        else
          newsize = capacity_*2;
        int * temp = new int[newsize];
        for(std::size_t i = 0; i<used_; ++i){
          temp[i] = data_[i];
        }
        delete [] data_;
        data_ = temp;
        temp = nullptr;
        capacity_ = newsize;

      }
      data_[used_] = target;
      ++used_;
    }

    // pre: none
    // post: adds to this DynamicBag a copy of each element of b
    void DynamicBag::operator += (const DynamicBag & b){//Homework!!
      assert(used_+b.size()<=capacity_);
      for(size_type i = 0; i<b.size(); ++i){
        insert(b[i]);
      }

    }

    // pre: none
    // post: if target appears in this DynamicBag, removes one copy of target and returns true
    //       else returns false
    //Why would we want to reallocate memory in erase_one??
    bool DynamicBag::erase_one(int target){
      size_type i = 0;
      for(i = 0; i<used_ &&data_[i]!=target; ++i){
      }
      if(i==used_)
        return false;
      else{
        for(size_type j = i; j<used_-1; ++j){
          data_[j] = data_[j+1];
        }
        --used_;
        return true;
      }
      if(used_<.25*capacity_){
        int* temp = new int[capacity_/2];
        for(size_type i = 0; i<used_; ++i)
          temp[i] = data_[i];
        delete [] data_;
        data_ = temp;
        temp = nullptr;
        capacity_ = .5*capacity_;
      }
    }

    // pre: none
    // post: if target appears in this DynamicBag k times, removes all copies and returns k
    //       else returns 0
    typename DynamicBag::size_type DynamicBag::erase(int target)
    {
      size_type count = 0;
      while(erase_one(target)){++count;}
      return count;
    }


// pre: b1.size() + b2.size() <= capacity_
// post: returns a DynamicBag containing all elements in b1 and b2
DynamicBag operator + (const DynamicBag & b1, const DynamicBag & b2){
  DynamicBag b;
  for(DynamicBag::size_type i = 0; i<b1.size(); ++i)
    b.insert(b1[i]);
  for(DynamicBag::size_type i = 0; i<b2.size(); ++i)
    b.insert(b2[i]);
  return b;
}

std::ostream& operator<<(std::ostream&  out, const DynamicBag& b){
  for(DynamicBag::size_type i = 0; i<b.size(); ++i)
    out<<b[i]<< " ";
  out<<std::endl;
  return out;
}
