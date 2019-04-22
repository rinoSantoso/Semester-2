#pragma once
#ifndef tri
#define tri

using namespace std;

class triangles {
public:

	void trimaker(int choice, int count) {
		//BottomLeft
		if (choice == 1) {
			for (int i = 1; i <= count; i++) {
				string stars(i, '*');
				cout << stars << '\n';
			}
		}
		//TopRight
		else if (choice == 2) {
			for (int i = 0; i < count; i++) {
				string stars(count - i, '*');
				string spaces(i, ' ');
				cout << spaces << stars << '\n';
			}
		}
		//TopLeft
		else if (choice == 3) {
			for (int i = 0; i < count; i++) {
				string stars(count - i, '*');
				cout << stars << '\n';
			}
		}
		//BottomRight
		else if (choice == 4) {
			for (int i = 1; i <= count; i++) {
				string stars(i, '*');
				string spaces(count - i, ' ');
				cout << spaces << stars << '\n';
			}
		}
		//Equilateral
		else if (choice == 5) {
			for (int i = 1; (i - 1) / 2 < count; i += 2) {
				string stars(i, '*');
				string spaces((count * 2 - 1 - i) / 2, ' ');
				cout << spaces << stars << spaces << '\n';
			}
		}
		//FlippedEquilateral
		else if (choice == 6) {
			for (int i = 0; (i) / 2 < count; i += 2) {
				string stars(count * 2 - i - 1, '*');
				string spaces(i / 2, ' ');
				cout << spaces << stars << spaces << '\n';
			}
		}
		//Diamond
		else if (choice == 7) {
			count = (count + 1) / 2;
			for (int i = 1; (i - 1) / 2 < count; i += 2) {
				string stars(i, '*');
				string spaces((count * 2 - 1 - i) / 2, ' ');
				cout << spaces << stars << spaces << '\n';
			}
			count -= 1;
			for (int n = 0; (n) / 2 < count; n += 2) {
				string stars(count * 2 - n - 1, '*');
				string spaces((n + 2) / 2, ' ');
				cout << spaces << stars << spaces << '\n';
			}
		}
		}
};
#endif