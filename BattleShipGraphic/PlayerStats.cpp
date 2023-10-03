#include "PlayerStats.h"

PlayerStats::PlayerStats()
{
	this->hits = 0;
	this->misses = 0;
	this->total_shots = 0;
}

PlayerStats::~PlayerStats()
{
}

int PlayerStats::getHits()
{
	return this->hits;
}

int PlayerStats::getMisses()
{
	return this->misses;
}

int PlayerStats::getTotal()
{
	return this->total_shots;
}

void PlayerStats::setHits(const int hits)
{
	this->hits = hits;
}

void PlayerStats::setMisses(const int misses)
{
	this->misses = misses;
}

void PlayerStats::setTotal(const int total)
{
	this->total_shots = total;
}

void PlayerStats::incrementHitsByOne()
{
	this->setHits(this->getHits() + 1);
	this->setTotal(this->getTotal() + 1);
}

void PlayerStats::incrementMissesByOne()
{
	this->setMisses(this->getMisses() + 1);
	this->setTotal(this->getTotal() + 1);
}
