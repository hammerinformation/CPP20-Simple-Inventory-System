#pragma once
#include<bitset>


template <std::size_t ItemCount,std::unsigned_integral T =unsigned short>
class SimpleInventorySystem
{
    T ItemCounts[ItemCount] = {};
    std::bitset<ItemCount> Items = 0;

public:
    void AddItem(const T item)
    {
        Items.set(item);
        ItemCounts[item] += 1;
    }

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

    template <class CastType=T>
    [[nodiscard]]
    CastType GetItemCount(const T item) const
    {
        return static_cast<CastType>(ItemCounts[item]);
    }
};
