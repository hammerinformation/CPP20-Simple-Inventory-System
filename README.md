
# C++20 Simple Inventory System 


This is a C++ template class for a simple inventory system. It keeps track of item counts and their presence using a bitset and an array. The system allows adding and removing items, and retrieving item counts with an option for type casting.
## Example

```cpp

namespace Items
{
    enum Item:unsigned char
    {
        Apple = 0,
        Pear = 1,
        Strawberry = 2
    };
}

int main()
{
    SimpleInventorySystem<5> MyItems;

    MyItems.AddItem(Items::Apple);
    MyItems.AddItem(Items::Apple);
    MyItems.AddItem(Items::Apple);
    MyItems.AddItem(Items::Apple);
    MyItems.AddItem(Items::Pear);
    const auto GetAppleCount = MyItems.GetItemCount(Items::Apple); // 4
    const auto GetAppleCount2 = MyItems.GetItemCount<long>(Items::Apple); //4
    MyItems.RemoveItem(Items::Apple);
    const auto GetAppleCount3 = MyItems.GetItemCount(Items::Apple); // 3
    const auto GetPearCount = MyItems.GetItemCount(Items::Pear); // 1


    return 0;
}
```


## Template Class For a Simple Inventory System

```cpp
template <std::size_t ItemCount,std::unsigned_integral T = unsigned short>
class SimpleInventorySystem
{
    T ItemCounts[ItemCount] = {};
    std::bitset<ItemCount> Items = 0;
}
```

## Add Item
```cpp
void AddItem(const T item)
{
    Items.set(item);
    ItemCounts[item] += 1;
}
```


## Remove Item 

```cpp
void RemoveItem(const T item)
{
  if (ItemCounts[item] > 0)
  {
       ItemCounts[item] -= 1;
  }
  if (ItemCounts[item] == 0)
  {
        Items.reset(item);
  }
}
```
## Get Item Count

```cpp
template <class CastType=T>
[[nodiscard]]
CastType GetItemCount(const T item) const
{
    return static_cast<CastType>(ItemCounts[item]);
}
```


