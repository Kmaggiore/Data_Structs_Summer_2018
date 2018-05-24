#include "HashTable.h"
#include <iomanip>  // for use of setw
#include <cstring>
#include <cmath>
using namespace std;

// Notes, Closed Hashing

void HashTable::rehash()
{
  Item *trash = data;
  size_type oldUsed = used;

  capacity = next_prime(2 * capacity);
  used = 0;

  cout << capacity << ' ';

  data = new Item [capacity];

  for(size_type i = 0; i < capacity; i++)
   strcpy(data[i].word, "");

  for(size_type i = 0; i < oldUsed; i++){
   if( !strcmp(trash[i].word, "") )
    insert(trash[i].word);
  }

  delete [] trash;
}

bool HashTable::exists(const char* cStr) const
{
   for (size_type i = 0; i < capacity; ++i)
      if ( ! strcmp(data[i].word, cStr) ) return true;

   return false;
}

bool HashTable::search(const char* cStr) const
{
  size_type ind1, ind0, i = 0;
  ind1 = ind0 = hash(cStr);

  while( i < capacity ){

    if( ! strcmp(data[ind1].word, cStr))
       return true;

     else
     {
       ++i;
       ind1 = (ind0 + (i * i)) % capacity;
     }
  }
   return false;
}

double HashTable::load_factor() const
{ return double(used) / capacity; }

HashTable::size_type HashTable::hash(const char* str) const
{
  unsigned long hash = 5381;
  int c;

  while ( (c = *str++) ) hash = ((hash << 5) + hash) + c;

  return (hash % capacity);
}

HashTable::HashTable(size_type initial_capacity)
          : capacity(initial_capacity), used(0)
{
   if (capacity < 11)
      capacity = next_prime(INIT_CAP);

   else if ( ! is_prime(capacity))
      capacity = next_prime(capacity);

   data = new Item[capacity];

   for (size_type i = 0; i < capacity; ++i)
      strcpy(data[i].word, "");
}

HashTable::~HashTable() { delete [] data; }

HashTable::size_type HashTable::cap() const
{ return capacity; }

HashTable::size_type HashTable::size() const
{ return used; }

void HashTable::scat_plot(ostream& out) const
{
   out << endl << "Scatter plot of where hash table is used:";
   size_type lo_index = 0,
             hi_index = capacity - 1,
             width;
   if (capacity >= 100000)
      width = capacity / 250;
   else if (capacity >= 10000)
      width = capacity / 25;
   else
      width = capacity / 10;
   size_type max_digits = size_type( floor( log10(hi_index) ) + 1 ),
             label_beg  = lo_index,
             label_end  = label_beg + width - 1;
   for(label_beg = lo_index; label_beg <= hi_index; label_beg += width)
   {
      out << endl;
      if( label_end > hi_index)
         out << setw(max_digits) << label_beg << " - " << setw(max_digits) << hi_index << ": ";
      else
         out << setw(max_digits) << label_beg << " - " << setw(max_digits) << label_end << ": ";
      size_type i = label_beg;
      while ( i <= label_end && i <= hi_index)
      {
         if (data[i].word[0] != '\0')
            out << '*';
         ++i;
      }
      label_end = label_end + width;
   }
   out << endl << endl;
}

void HashTable::grading_helper_print(ostream& out) const
{
   out << endl << "Content of selected hash table segment:\n";
   for (size_type i = 10; i < 30; ++i)
      out << '[' << i << "]: " << data[i].word << endl;
}

void HashTable::insert(const char* cStr)
{
  size_type loc0, loc1, i = 0;
  loc1 = loc0 = hash(cStr);

  while(i < capacity)
  {
    if ( ! strcmp(data[loc1].word, "") )
    {
        strcpy(data[loc1].word, cStr);
        ++used;
        break;
    }
     else
     {
        ++i;
        loc1 = (loc0 + (i * i)) % capacity;
     }
   }

  if ( load_factor() > 0.45 )
    rehash();
}

bool is_prime(HashTable::size_type x)
{
   if (x <= 3 || x == 5) return true;
   if (x == 4 || x == 6) return false;

   HashTable::size_type inc = 4;
   for (HashTable::size_type i = 5; true; i += inc)
   {
      HashTable::size_type q = x / i;
      if (q < i)
         return true;
      if (x == q * i)
         return false;
      inc ^= 6;
   }
   return true;
}

HashTable::size_type next_prime(HashTable::size_type x)
{
    switch (x)
    {
    case 0:
    case 1:
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
    case 5:
        return 5;
    }
    HashTable::size_type k = x / 6;
    HashTable::size_type i = x - 6 * k;
    HashTable::size_type inc = i < 2 ? 1 : 5;
    x = 6 * k + inc;
    for (i = (3 + inc) / 2; !is_prime(x); x += i)
        i ^= 6;
    return x;
}
