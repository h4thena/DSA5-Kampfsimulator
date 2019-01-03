#pragma once
#include <string>
#include <vector>

struct weapon {
	std::string name = "myweapon";
	unsigned int at = 0;
	unsigned int pa = 0;
	unsigned int rw = 0;
	unsigned int loadDuration = 0;
};

struct spell {
	std::string name = "myspell";
	unsigned int at = 0;
	unsigned int rw = 0;
	unsigned int cost = 0;
	unsigned int spellDuration = 0;
	unsigned int effectDuration = 0;
};

class Entity {
public:
	Entity();
	~Entity();

	std::string name = "name";

	unsigned int mu = 0;
	unsigned int kl = 0;
	unsigned int in = 0;
	unsigned int ch = 0;
	unsigned int ff = 0;
	unsigned int ge = 0;
	unsigned int ko = 0;
	unsigned int kk = 0;

	unsigned int lep = 0;
	unsigned int asp = 0;
	unsigned int kap = 0;
	unsigned int sk = 0;
	unsigned int zk = 0;
	unsigned int aw = 0;
	unsigned int ini = 0;
	unsigned int gw = 0;

	std::vector<weapon> weapons;
	std::vector<spell> spells;
};

