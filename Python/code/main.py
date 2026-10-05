from Item import Item
from Player import Player
from NPC import NPC


# =========================================================
# FUNGSI INPUT
# =========================================================

# Menerima input integer dan mengulang jika input tidak valid.
def input_integer(pesan):
    while True:
        try:
            return int(input(pesan))
        except ValueError:
            print("Error: input harus berupa angka.")


# Menerima input integer dengan batas minimum.
def input_integer_min(pesan, nilai_minimum):
    while True:
        nilai = input_integer(pesan)

        if nilai >= nilai_minimum:
            return nilai

        print(f"Error: nilai minimal adalah {nilai_minimum}.")


# Menerima input float dan mengulang jika input tidak valid.
def input_float(pesan):
    while True:
        try:
            return float(input(pesan))
        except ValueError:
            print("Error: input harus berupa angka.")


# Menerima input float dengan batas minimum.
def input_float_min(pesan, nilai_minimum):
    while True:
        nilai = input_float(pesan)

        if nilai >= nilai_minimum:
            return nilai

        print(f"Error: nilai minimal adalah {nilai_minimum}.")


# Menerima string yang tidak boleh kosong.
def input_string(pesan):
    while True:
        nilai = input(pesan)

        if nilai:
            return nilai

        print("Error: input tidak boleh kosong.")


# =========================================================
# FUNGSI CEK ID KARAKTER
# =========================================================

# Mengecek apakah ID sudah digunakan oleh Player atau NPC.
def id_karakter_sudah_ada(id_karakter, daftar_player, daftar_npc):
    for player in daftar_player:
        if player.get_id() == id_karakter:
            return True

    for npc in daftar_npc:
        if npc.get_id() == id_karakter:
            return True

    return False

# =========================================================
# FUNGSI CEK ID ITEM
# =========================================================

# Mengecek apakah ID Item sudah digunakan di dalam Inventory.
# ID Item harus unik agar setiap Item dapat dibedakan dengan jelas.
def id_item_sudah_ada(id_item, daftar_item):
    # Mengecek ID pada seluruh Item yang sudah tersimpan.
    for item in daftar_item:
        if item.get_id_item() == id_item:
            return True

    return False

# =========================================================
# FUNGSI TAMBAH PLAYER
# =========================================================

# Membuat Player baru beserta Inventory dan Item-nya melalui input terminal.
def tambah_player(daftar_player, daftar_npc):
    print()
    print("============================================")
    print("              TAMBAH PLAYER                 ")
    print("============================================")

    # Meminta ID karakter yang unik di seluruh Player dan NPC.
    while True:
        id_karakter = input_string("ID              : ")

        if not id_karakter_sudah_ada(id_karakter, daftar_player, daftar_npc):
            break

        print("Error: ID sudah digunakan oleh karakter lain.")

    nama = input_string("Nama            : ")
    level = input_integer_min("Level           : ", 0)
    max_hp = input_integer_min("Max HP          : ", 1)

    # Memastikan HP tidak melebihi max HP.
    while True:
        hp = input_integer_min("HP              : ", 0)

        if hp <= max_hp:
            break

        print("Error: HP tidak boleh lebih besar dari Max HP.")

    exp = input_integer_min("Experience      : ", 0)
    gold = input_integer_min("Gold            : ", 0)

    # Membuat Player dengan atribut dasar dan atribut khusus Player.
    player = Player(id_karakter, nama, level, hp, max_hp, exp, gold)

    # Meminta kapasitas Inventory.
    kapasitas = input_integer_min("Kapasitas Inventory : ", 1)
    player.get_inventory().set_kapasitas_maksimal(kapasitas)

    # Jumlah Item tidak boleh melebihi kapasitas Inventory.
    while True:
        jumlah_item = input_integer_min("Jumlah Item        : ", 0)

        if jumlah_item <= kapasitas:
            break

        print(
            "Error: jumlah Item tidak boleh melebihi "
            f"kapasitas Inventory ({kapasitas})."
        )

    # Membuat setiap Item berdasarkan input.
    for nomor in range(1, jumlah_item + 1):
        print()
        print(f"Item ke-{nomor}")

        # ID Item harus unik di dalam Inventory Player.
        while True:
            id_item = input_string("ID Item         : ")

            if not id_item_sudah_ada(
                id_item,
                player.get_inventory().get_daftar_item()
            ):
                break

            print("Error: ID Item sudah digunakan dalam Inventory Player ini.")

        nama_item = input_string("Nama Item       : ")
        tipe_item = input_string("Tipe Item       : ")
        berat = input_float_min("Berat (kg)      : ", 0)
        harga_jual = input_integer_min("Harga Jual      : Rp", 0)
        quantity = input_integer_min("Quantity        : ", 0)

        item = Item(
            id_item,
            nama_item,
            tipe_item,
            berat,
            harga_jual,
            quantity
        )
        player.get_inventory().tambah_item(item)

    daftar_player.append(player)
    print()
    print("Player berhasil ditambahkan.")


# =========================================================
# FUNGSI TAMBAH NPC
# =========================================================

# Membuat NPC baru beserta dialognya melalui input terminal.
def tambah_npc(daftar_npc, daftar_player):
    print()
    print("============================================")
    print("                TAMBAH NPC                  ")
    print("============================================")

    # Meminta ID karakter yang unik di seluruh Player dan NPC.
    while True:
        id_karakter = input_string("ID              : ")

        if not id_karakter_sudah_ada(id_karakter, daftar_player, daftar_npc):
            break

        print("Error: ID sudah digunakan oleh karakter lain.")

    nama = input_string("Nama            : ")
    level = input_integer_min("Level           : ", 0)
    max_hp = input_integer_min("Max HP          : ", 1)

    # Memastikan HP tidak melebihi max HP.
    while True:
        hp = input_integer_min("HP              : ", 0)

        if hp <= max_hp:
            break

        print("Error: HP tidak boleh lebih besar dari Max HP.")

    print()
    print("Tipe / peran NPC di dalam game.")
    print("Contoh: Penjual, Pemberi Quest, atau Musuh.")
    tipe_npc = input_string("Tipe NPC        : ")

    print()
    print("Apakah NPC bersifat agresif dan dapat menyerang Player?")
    print("1 = Ya, NPC bersifat agresif/musuh.")
    print("0 = Tidak, NPC tidak menyerang Player.")

    # Memastikan input status hostile hanya 0 atau 1.
    while True:
        hostile_input = input_integer("Hostile? (1 = Ya, 0 = Tidak): ")

        if hostile_input in (0, 1):
            break

        print("Error: masukkan 1 atau 0.")

    is_hostile = hostile_input == 1
    jumlah_dialog = input_integer_min("Jumlah Dialog   : ", 1)
    dialog_list = []

    # Meminta setiap dialog NPC.
    for nomor in range(1, jumlah_dialog + 1):
        dialog = input_string(f"Dialog ke-{nomor} : ")
        dialog_list.append(dialog)

    npc = NPC(
        id_karakter,
        nama,
        level,
        hp,
        max_hp,
        tipe_npc,
        is_hostile,
        dialog_list
    )

    daftar_npc.append(npc)
    print()
    print("NPC berhasil ditambahkan.")


# =========================================================
# FUNGSI TAMPILKAN SEMUA DATA
# =========================================================

# Menampilkan seluruh Player, Inventory, Item, dan NPC.
def tampilkan_semua_data(daftar_player, daftar_npc):
    print()
    print("============================================")
    print("              DATA GAME                     ")
    print("============================================")

    print()
    print("--------------- PLAYER --------------------")

    if not daftar_player:
        print("Belum ada data Player.")
    else:
        for nomor, player in enumerate(daftar_player, start=1):
            print()
            print(f"Player ke-{nomor}")
            print("--------------------------------------------")
            player.tampilkan_info()

            print()
            print("Inventory:")
            player.get_inventory().tampilkan_info()

    print()
    print("---------------- NPC ----------------------")

    if not daftar_npc:
        print("Belum ada data NPC.")
    else:
        for nomor, npc in enumerate(daftar_npc, start=1):
            print()
            print(f"NPC ke-{nomor}")
            print("--------------------------------------------")
            npc.tampilkan_info()


# =========================================================
# PROGRAM UTAMA
# =========================================================

def main():
    # Membuat Item awal.
    pedang = Item("I001", "Pedang Besi", "Senjata", 5.0, 500, 1)
    potion = Item("I002", "Ramuan Penyembuh", "Konsumsi", 0.5, 100, 5)
    armor = Item("I003", "Armor Besi", "Armor", 8.0, 750, 1)

    # Membuat Player awal beserta Inventory dan Item-nya.
    player1 = Player("P001", "Kiryu", 10, 100, 100, 2500, 1000)
    player1.get_inventory().set_kapasitas_maksimal(5)
    player1.get_inventory().tambah_item(pedang)
    player1.get_inventory().tambah_item(potion)

    player2 = Player("P002", "Akira", 7, 80, 100, 1500, 750)
    player2.get_inventory().set_kapasitas_maksimal(5)
    player2.get_inventory().tambah_item(armor)

    daftar_player = [player1, player2]

    # Membuat NPC awal beserta daftar dialognya.
    dialog_merchant = [
        "Selamat datang di toko!",
        "Apakah kamu ingin membeli sesuatu?"
    ]
    merchant = NPC(
        "N001", "Merchant", 5, 80, 80,
        "Penjual", False, dialog_merchant
    )

    dialog_enemy = [
        "Berani sekali kamu datang ke sini!",
        "Aku akan mengalahkanmu!"
    ]
    goblin = NPC(
        "N002", "Goblin", 8, 120, 120,
        "Musuh", True, dialog_enemy
    )

    daftar_npc = [merchant, goblin]

    # Menampilkan data awal sebelum menu dijalankan.
    print()
    print("============================================")
    print("       DATA GAME SEBELUM DITAMBAHKAN        ")
    print("============================================")
    tampilkan_semua_data(daftar_player, daftar_npc)

    # Menampilkan menu sampai user memilih keluar.
    while True:
        print()
        print("============================================")
        print("                MENU GAME                   ")
        print("============================================")
        print("1. Tambah Player")
        print("2. Tambah NPC")
        print("3. Tampilkan Semua Data")
        print("0. Keluar")
        print("============================================")

        pilihan = input_integer("Pilih menu: ")

        if pilihan == 1:
            tambah_player(daftar_player, daftar_npc)
        elif pilihan == 2:
            tambah_npc(daftar_npc, daftar_player)
        elif pilihan == 3:
            tampilkan_semua_data(daftar_player, daftar_npc)
        elif pilihan == 0:
            print()
            print("Program selesai.")
            break
        else:
            print("Error: pilihan menu tidak tersedia.")

    # Menampilkan seluruh data terbaru sebelum program berakhir.
    print()
    print("============================================")
    print("        DATA GAME SETELAH DITAMBAHKAN       ")
    print("============================================")
    tampilkan_semua_data(daftar_player, daftar_npc)


if __name__ == "__main__":
    main()