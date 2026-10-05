from Karakter import Karakter
from Inventory import Inventory


class Player(Karakter):
    # =========================
    # ATTRIBUTE DAN CONSTRUCTOR
    # =========================

    # Constructor ini juga mewakili constructor kosong.
    # Atribut Karakter diinisialisasi melalui constructor parent.
    # Inventory dibuat sebagai bagian dari object Player (composition).
    def __init__(
        self,
        id="",
        nama="",
        level=0,
        hp=0,
        max_hp=0,
        exp=0,
        gold=0
    ):
        super().__init__(id, nama, level, hp, max_hp)
        self.__exp = exp
        self.__gold = gold
        self.__inventory = Inventory()

    # =========================
    # METHOD SETTER & GETTER
    # =========================

    # Setter exp digunakan untuk mengubah jumlah experience point Player.
    # Experience tidak boleh bernilai negatif.
    def set_exp(self, exp):
        if exp >= 0:
            self.__exp = exp
        else:
            print("Error: experience point tidak boleh negatif.")

    # Getter exp digunakan untuk mengambil jumlah experience point Player.
    def get_exp(self):
        return self.__exp

    # Setter gold digunakan untuk mengubah jumlah gold Player.
    # Gold tidak boleh bernilai negatif.
    def set_gold(self, gold):
        if gold >= 0:
            self.__gold = gold
        else:
            print("Error: gold tidak boleh negatif.")

    # Getter gold digunakan untuk mengambil jumlah gold Player.
    def get_gold(self):
        return self.__gold

    # Getter inventory digunakan untuk mengakses dan memodifikasi Inventory.
    def get_inventory(self):
        return self.__inventory

    # =========================
    # METHOD LAIN
    # =========================

    # Menampilkan seluruh informasi Player.
    # Informasi dasar ditampilkan oleh method class Karakter.
    def tampilkan_info(self):
        super().tampilkan_info()
        print(f"EXP             : {self.__exp}")
        print(f"Gold            : {self.__gold}")