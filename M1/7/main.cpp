/* Задача 7.1
В город N приехал цирк с командой атлетов. 
Они хотят удивить горожан города N — выстроить из своих тел башню максимальной высоты. 
Башня — это цепочка атлетов, первый стоит на земле, 
второй стоит у него на плечах, третий стоит на плечах у второго и т.д.
Каждый атлет характеризуется силой si (kg) и массой mi (kg).
Сила — это максимальная масса, которую атлет способен держать у себя на плечах.
*/

#include <iostream>
#include <algorithm>


struct Player {
	unsigned weight, strength;
};

class Ensemble {
	public:
		Player *players;
		size_t count;
		
		Ensemble():count(0), size(1) { players = new Player[size]; }
		~Ensemble() { delete[] players; }

		void resize_array() {
			Player *tmp = new Player[size *= 2];
			for (unsigned i = 0; i < count; ++i) {
				tmp[i] = players[i];
			}
			delete[] players;
			players = tmp;
		}

		void invite_player(Player player) {
			if (count == size) {
				this->resize_array();
			}
			players[count] = player;
			++count;
		}

	private:
		size_t size;
};

int cmp(const Player& pl1, const Player& pl2) {
	return pl1.strength < pl2.strength;
}

int get_CountPlayers(Player *players, size_t count) {
	unsigned countPlayers = 0, weightPlayers = 0;
	for (unsigned i = 0; i < count; ++i) {
		//Если текущий может выдержать всех предыдущих, то добавляем
		if (players[i].strength >= weightPlayers) {
			++countPlayers;
			weightPlayers += players[i].weight;
		}
	}
	return countPlayers;
}

int main() {
	Ensemble ensemble;

	//Пока не конец потока добавляем спортсменов
	while(!feof(stdin)) {
		Player player;
		std::cin >> player.weight >> player.strength;
		ensemble.invite_player(player);
	}

	//Сортировка по силе
	std::sort(ensemble.players, ensemble.players + ensemble.count, cmp);

	int countPlayers = get_CountPlayers(ensemble.players, ensemble.count);
	std::cout << countPlayers;

	return 0;
}