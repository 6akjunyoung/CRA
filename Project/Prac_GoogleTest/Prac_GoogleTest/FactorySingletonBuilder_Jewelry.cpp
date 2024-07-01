#include <iostream>
#include <string>
#define interface struct
using namespace std;

interface Jewelry {
	virtual void showInfo() = 0;
};

class Gold : public Jewelry {
public:
	class Builder {
	public:
		Builder& setAlias(string alias) {
			this->alias = alias;
			return *this;
		}

		Builder& setPrice(int price) {
			this->price = price;
			return *this;
		}

		Gold& build() {
			return *(new Gold{ alias, price });
		}

	private:
		string alias;
		int price;
	};

	void showInfo() override {
		cout << "GOLD : " << alias << ", $" << price << "\n";
	}
private:
	Gold(string alias, int price)
		: alias{ alias }, price{ price } { }

	string alias;
	int price;
};

class Ruby : public Jewelry {
public:
	Ruby(string alias, int price)
		: alias{ alias }, price{ price } { }
	void showInfo() override {
		cout << "Ruby : " << alias << ", $" << price << "\n";
	}
private:
	string alias;
	int price;
};

class Diamond : public Jewelry {
public:
	Diamond(string alias, int price)
		: alias{ alias }, price{ price } { }
	void showInfo() override {
		cout << "Diamond : " << alias << ", $" << price << "\n";
	}
private:
	string alias;
	int price;
};

class JewelryFactory {
public:
	static JewelryFactory& getInstance() {
		static JewelryFactory instance;
		return instance;
	}

	Jewelry& makeJewelry(string name, string alias, int price) {
		if (name == "ruby") return *(new Ruby(alias, price));
		if (name == "diamond") return *(new Diamond(alias, price));

		//Gold는 빌더로 구현
		return Gold::Builder().setAlias(alias).setPrice(price).build();
	}

private:
	JewelryFactory() {}
	JewelryFactory& operator=(const JewelryFactory& other) = delete;
	JewelryFactory(const JewelryFactory& other) = delete;
};

int main() {
	JewelryFactory& fac = JewelryFactory::getInstance();
	Jewelry& mine = fac.makeJewelry("gold", "baby", 1000);

	mine.showInfo();
}