#ifndef ITEMS_H
#define ITEMS_H

enum ItemType
{
   ITEM_APPLE,
   ITEM_CUTTED_APPLE,
   ITEM_BANANA,
   ITEM_CUTTED_BANANA
};

struct Item
{
   ItemType type;
};

#endif // ITEMS_H
