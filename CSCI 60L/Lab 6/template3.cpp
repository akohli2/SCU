#include "template3.h"


template <typename T>
template3<T>::template3()
{
  dimension=0;
}


template <typename T>
template3<T>::template3(int dim)
{
  dimension=dim;
  for(int i=0;i<10;i++)
  {
    arr[i]=T();
  }
}


template <typename T>
template3<T>::template3(int dim, T a[])
{
  dimension=dim;
  for(int i=0;i<10;i++)
  {
    arr[i]=a[i];
  }
}
