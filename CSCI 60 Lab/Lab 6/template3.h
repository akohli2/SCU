#ifndef TEMPLATE3_H
#define TEMPLATE3_H




template <typename T>
class template3
{
private:
  T arr[10];
  int dimension;

public:
template3();
  template3(int dim);
  template3(int dim, T a[]);
  int dimension_(){ return dimension;}
  T index(T a[], int i){ return a[i];}

void operator =(template3 d)
{
  dimension = d.dimension_();
  for (int i = 0; i < dimension; i++) {
    arr[i] = d.index(d.arr,i);
  }
}
};


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
  for(int i=0;i<dim;i++)
  {
    arr[i]=a[i];
  }
}




#endif
