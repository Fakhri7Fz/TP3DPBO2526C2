# from Item import Item


class Inventory:
    # =========================
    # ATTRIBUTE DAN CONSTRUCTOR
    # =========================

    # Constructor ini juga mewakili constructor kosong.
    # Kapasitas default adalah 0 dan daftar item dimulai dalam keadaan kosong.
    def __init__(self, kapasitas_maksimal=0):
        self.__kapasitas_maksimal = kapasitas_maksimal
        self.__daftar_item = []

    # =========================
    # METHOD SETTER & GETTER
    # =========================

    # Setter kapasitas maksimal digunakan untuk mengubah kapasitas Inventory.
    # Kapasitas tidak boleh lebih kecil dari jumlah item yang sudah tersimpan.
    def set_kapasitas_maksimal(self, kapasitas_maksimal):
        if kapasitas_maksimal < 0:
            print("Error: kapasitas tidak boleh negatif.")
        elif kapasitas_maksimal < len(self.__daftar_item):
            print("Error: kapasitas tidak boleh lebih kecil dari jumlah item saat ini.")
        else:
            self.__kapasitas_maksimal = kapasitas_maksimal

    # Getter kapasitas maksimal digunakan untuk mengambil kapasitas Inventory.
    def get_kapasitas_maksimal(self):
        return self.__kapasitas_maksimal

    # Getter daftar item mengembalikan salinan daftar item Inventory.
    def get_daftar_item(self):
        return list(self.__daftar_item)

    # =========================
    # METHOD LAIN
    # =========================

    # Menambahkan object Item jika Inventory masih memiliki slot kosong.
    def tambah_item(self, item):
        if len(self.__daftar_item) < self.__kapasitas_maksimal:
            self.__daftar_item.append(item)
        else:
            print("Error: Inventory sudah penuh.")

    # Menampilkan kapasitas dan seluruh Item yang tersimpan di dalam Inventory.
    def tampilkan_info(self):
        print(
            f"Kapasitas       : "
            f"{len(self.__daftar_item)}/{self.__kapasitas_maksimal}"
        )
        print("Daftar Item:")

        if not self.__daftar_item:
            print("  Inventory kosong.")
        else:
            # Menampilkan informasi setiap Item yang tersimpan.
            for nomor, item in enumerate(self.__daftar_item, start=1):
                print()
                print(f"  Item ke-{nomor}")
                print(f"  ID Item       : {item.get_id_item()}")
                print(f"  Nama Item     : {item.get_nama_item()}")
                print(f"  Tipe Item     : {item.get_tipe_item()}")
                print(f"  Berat         : {item.get_berat()} kg")
                print(f"  Harga Jual    : Rp{item.get_harga_jual()}")
                print(f"  Quantity      : {item.get_quantity()}")