#pragma once
#include "Board.h"

class PlayerStats {
private:
	int hits;
	int misses;
	int total_shots;

public:
	PlayerStats();

	~PlayerStats();


	//Getters/Setters
	int getHits();

	int getMisses();

	int getTotal();

	void setHits(const int hits);

	void setMisses(const int misses);

	void setTotal(const int total);

	
	//Helper Methods
	void incrementHitsByOne();

	void incrementMissesByOne();
};

