class Item:
    # =========================
    # ATTRIBUTE DAN CONSTRUCTOR
    # =========================

    # Constructor ini juga mewakili constructor tanpa parameter.
    # Nilai default digunakan agar seluruh atribut terinisialisasi.
    def __init__(
        self,
        id_item="",
        nama_item="",
        tipe_item="",
        berat=0.0,
        harga_jual=0,
        quantity=0
    ):
        self.__id_item = id_item
        self.__nama_item = nama_item
        self.__tipe_item = tipe_item
        self.__berat = berat
        self.__harga_jual = harga_jual
        self.__quantity = quantity

    # =========================
    # METHOD SETTER & GETTER
    # =========================

    # Setter id item digunakan untuk mengubah ID Item.
    def set_id_item(self, id_item):
        self.__id_item = id_item

    # Getter id item digunakan untuk mengambil ID Item.
    def get_id_item(self):
        return self.__id_item

    # Setter nama item digunakan untuk mengubah nama Item.
    def set_nama_item(self, nama_item):
        self.__nama_item = nama_item

    # Getter nama item digunakan untuk mengambil nama Item.
    def get_nama_item(self):
        return self.__nama_item

    # Setter tipe item digunakan untuk mengubah kategori Item.
    def set_tipe_item(self, tipe_item):
        self.__tipe_item = tipe_item

    # Getter tipe item digunakan untuk mengambil kategori Item.
    def get_tipe_item(self):
        return self.__tipe_item

    # Setter berat digunakan untuk mengubah berat Item.
    # Berat tidak boleh bernilai negatif.
    def set_berat(self, berat):
        if berat >= 0:
            self.__berat = berat
        else:
            print("Error: berat item tidak boleh negatif.")

    # Getter berat digunakan untuk mengambil berat Item.
    def get_berat(self):
        return self.__berat

    # Setter harga jual digunakan untuk mengubah harga jual Item.
    # Harga jual tidak boleh bernilai negatif.
    def set_harga_jual(self, harga_jual):
        if harga_jual >= 0:
            self.__harga_jual = harga_jual
        else:
            print("Error: harga jual tidak boleh negatif.")

    # Getter harga jual digunakan untuk mengambil harga jual Item.
    def get_harga_jual(self):
        return self.__harga_jual

    # Setter quantity digunakan untuk mengubah jumlah Item.
    # Quantity tidak boleh bernilai negatif.
    def set_quantity(self, quantity):
        if quantity >= 0:
            self.__quantity = quantity
        else:
            print("Error: quantity tidak boleh negatif.")

    # Getter quantity digunakan untuk mengambil jumlah Item.
    def get_quantity(self):
        return self.__quantity

    # =========================
    # METHOD LAIN
    # =========================

    # Menampilkan seluruh informasi Item.
    def tampilkan_info(self):
        print(f"ID Item         : {self.__id_item}")
        print(f"Nama Item       : {self.__nama_item}")
        print(f"Tipe Item       : {self.__tipe_item}")
        print(f"Berat           : {self.__berat} kg")
        print(f"Harga Jual      : Rp{self.__harga_jual}")
        print(f"Quantity        : {self.__quantity}")