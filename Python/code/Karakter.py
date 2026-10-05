class Karakter:
    # =========================
    # ATTRIBUTE DAN CONSTRUCTOR
    # =========================

    # Constructor ini juga mewakili constructor kosong.
    # Nilai default digunakan agar atribut tetap terinisialisasi.
    def __init__(self, id="", nama="", level=0, hp=0, max_hp=0):
        self._id = id
        self._nama = nama
        self._level = level
        self._hp = hp
        self._max_hp = max_hp

    # =========================
    # METHOD SETTER & GETTER
    # =========================

    # Setter id digunakan untuk mengubah ID karakter.
    def set_id(self, id):
        self._id = id

    # Getter id digunakan untuk mengambil ID karakter.
    def get_id(self):
        return self._id

    # Setter nama digunakan untuk mengubah nama karakter.
    def set_nama(self, nama):
        self._nama = nama

    # Getter nama digunakan untuk mengambil nama karakter.
    def get_nama(self):
        return self._nama

    # Setter level digunakan untuk mengubah level karakter.
    # Level tidak boleh bernilai negatif.
    def set_level(self, level):
        if level >= 0:
            self._level = level
        else:
            print("Error: level tidak boleh negatif.")

    # Getter level digunakan untuk mengambil level karakter.
    def get_level(self):
        return self._level

    # Setter hp digunakan untuk mengubah health point karakter.
    # HP harus berada di antara 0 dan max_hp.
    def set_hp(self, hp):
        if 0 <= hp <= self._max_hp:
            self._hp = hp
        elif hp < 0:
            print("Error: HP tidak boleh negatif.")
        else:
            print("Error: HP tidak boleh melebihi max HP.")

    # Getter hp digunakan untuk mengambil health point karakter.
    def get_hp(self):
        return self._hp

    # Setter max HP digunakan untuk mengubah batas maksimum HP.
    # Max HP harus lebih dari 0 dan tidak boleh lebih kecil dari HP saat ini.
    def set_max_hp(self, max_hp):
        if max_hp > 0 and max_hp >= self._hp:
            self._max_hp = max_hp
        elif max_hp <= 0:
            print("Error: max HP harus lebih dari 0.")
        else:
            print("Error: max HP tidak boleh lebih kecil dari HP saat ini.")

    # Getter max HP digunakan untuk mengambil batas maksimum HP.
    def get_max_hp(self):
        return self._max_hp

    # =========================
    # METHOD LAIN
    # =========================

    # Menampilkan seluruh informasi dasar Karakter.
    # Method ini dapat digunakan oleh object Karakter maupun class turunannya.
    def tampilkan_info(self):
        print(f"ID              : {self._id}")
        print(f"Nama            : {self._nama}")
        print(f"Level           : {self._level}")
        print(f"HP              : {self._hp}/{self._max_hp}")