#include"hash.h"

int main()
{
  
  student a;
  student b("Bobby", "B", 3, 2);
  student c("Corver", "C", 2, 3);
  student d("Dobby", "D", 4, 4);
  student e("Eric", "E", 1.5, 5);
  student f("Fred", "F", 2.5, 101);
  student g("Gordon", "G", 3.6, 201);
  list l;
  hashTable ha;
  
  a.setFirst("A");
  cout << a.getFirst() << endl;
  a.setLast("B");
  cout << a.getLast() << endl;
  a.setGpa(3);
  cout << a.getGpa() << endl;
  a.setId(20);
  cout << a.getId() << endl << "LIST:\n";
  
  ha.add(a);
  ha.add(b);
  ha.add(c);
  ha.add(d);
  ha.add(e);
  ha.add(f);
  ha.add(g);
  cout << " - - - - \n";
  ha.display();
  cout << " - - - - \n";
  ha.rem(20);
  ha.rem(201);
  ha.rem(4);
  ha.display();
  return 0;
  
}
