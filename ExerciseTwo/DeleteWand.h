#ifndef DeleteWand_H
#define DeleteWand_H

void DeleteFilteredWandsFromStorage(std::list<Wand>& wandStorage, const std::list<Wand>& filteredWands);
void DeleteAllWands(std::list<Wand>& wandStorage);

#endif