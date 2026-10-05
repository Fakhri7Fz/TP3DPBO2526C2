from Karakter import Karakter

class NPC(Karakter):
    # =========================
    # ATTRIBUTE DAN CONSTRUCTOR
    # =========================

    # Constructor ini juga mewakili constructor kosong.
    # Atribut dasar Karakter diinisialisasi melalui constructor parent.
    # dialog_list disalin agar object NPC memiliki kumpulan dialog sendiri.
    def __init__(
        self,
        id="",
        nama="",
        level=0,
        hp=0,
        max_hp=0,
        tipe_npc="",
        is_hostile=False,
        dialog_list=None
    ):
        super().__init__(id, nama, level, hp, max_hp)
        self.__tipe_npc = tipe_npc
        self.__is_hostile = is_hostile
        # Salin dialog yang diberikan, atau gunakan list kosong jika tidak ada.
        self.__dialog_list = list(dialog_list) if dialog_list is not None else []

    # =========================
    # METHOD SETTER & GETTER
    # =========================

    # Setter tipe NPC digunakan untuk mengubah peran NPC.
    def set_tipe_npc(self, tipe_npc):
        self.__tipe_npc = tipe_npc

    # Getter tipe NPC digunakan untuk mengambil peran NPC.
    def get_tipe_npc(self):
        return self.__tipe_npc

    # Setter is_hostile digunakan untuk mengubah status agresivitas NPC.
    def set_is_hostile(self, is_hostile):
        self.__is_hostile = is_hostile

    # Getter is_hostile digunakan untuk mengambil status agresivitas NPC.
    def get_is_hostile(self):
        return self.__is_hostile

    # Setter dialog list digunakan untuk mengganti seluruh kumpulan dialog NPC.
    # Kumpulan dialog disalin agar perubahan dari luar tidak mengubah atribut NPC.
    def set_dialog_list(self, dialog_list):
        self.__dialog_list = list(dialog_list)

    # Getter dialog list digunakan untuk mengambil seluruh kumpulan dialog NPC.
    # Salinan list dikembalikan agar atribut internal tidak diubah langsung.
    def get_dialog_list(self):
        return list(self.__dialog_list)

    # =========================
    # METHOD LAIN
    # =========================

    # Menampilkan seluruh informasi NPC.
    # Informasi dasar karakter ditampilkan oleh class Karakter.
    def tampilkan_info(self):
        super().tampilkan_info()
        print(f"Tipe NPC        : {self.__tipe_npc}")
        print(f"Hostile         : {'Ya' if self.__is_hostile else 'Tidak'}")
        print("Dialog          :")

        # Menampilkan seluruh dialog yang dimiliki NPC.
        for dialog in self.__dialog_list:
            print(f"  - {dialog}")