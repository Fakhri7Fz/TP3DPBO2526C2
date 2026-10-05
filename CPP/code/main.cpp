#include <bits/stdc++.h>

using namespace std;

// =========================================================
// INCLUDE CLASS
// =========================================================

// Item digunakan oleh Inventory.
#include "Item.cpp"

// Inventory menggunakan Item.
#include "Inventory.cpp"

// Karakter merupakan parent dari Player dan NPC.
#include "Karakter.cpp"

// Player mewarisi Karakter dan memiliki Inventory.
#include "Player.cpp"

// NPC mewarisi Karakter.
#include "NPC.cpp"

// =========================================================
// FUNGSI INPUT
// =========================================================

// Fungsi untuk menerima input integer.
// Input akan terus diminta sampai user memasukkan angka yang valid.
int inputInteger(string pesan)
{
    int nilai;

    while (true)
    {
        cout << pesan;

        if (cin >> nilai)
        {
            cin.ignore(1000, '\n');
            return nilai;
        }

        cout << "Error: input harus berupa angka.\n";

        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// Fungsi untuk menerima input integer dengan batas minimum.
int inputIntegerMin(string pesan, int min)
{
    int nilai;

    while (true)
    {
        nilai = inputInteger(pesan);

        if (nilai >= min)
        {
            return nilai;
        }

        cout << "Error: nilai minimal adalah " << min << ".\n";
    }
}

// Fungsi untuk menerima input float.
// Digunakan untuk input yang dapat memiliki nilai desimal, seperti berat Item.
float inputFloat(string pesan)
{
    float nilai;

    while (true)
    {
        cout << pesan;

        if (cin >> nilai)
        {
            cin.ignore(1000, '\n');
            return nilai;
        }

        cout << "Error: input harus berupa angka.\n";

        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// Fungsi untuk menerima float dengan batas minimum.
float inputFloatMin(string pesan, float min)
{
    float nilai;

    while (true)
    {
        nilai = inputFloat(pesan);

        if (nilai >= min)
        {
            return nilai;
        }

        cout << "Error: nilai minimal adalah " << min << ".\n";
    }
}

// Fungsi untuk menerima input string.
// String tidak boleh kosong.
string inputString(string pesan)
{
    string nilai;

    while (true)
    {
        cout << pesan;
        getline(cin, nilai);

        if (!nilai.empty())
        {
            return nilai;
        }

        cout << "Error: input tidak boleh kosong.\n";
    }
}

// =========================================================
// FUNGSI CEK ID KARAKTER
// =========================================================

// Mengecek apakah ID sudah digunakan oleh Player atau NPC.
// ID karakter harus unik di seluruh data Player dan NPC.
bool idKarakterSudahAda(
    string id,
    const vector<Player> &daftar_player,
    const vector<NPC> &daftar_npc)
{
    // Mengecek ID pada seluruh Player.
    for (int i = 0; i < daftar_player.size(); i++)
    {
        if (daftar_player[i].getId() == id)
        {
            return true;
        }
    }

    // Mengecek ID pada seluruh NPC.
    for (int i = 0; i < daftar_npc.size(); i++)
    {
        if (daftar_npc[i].getId() == id)
        {
            return true;
        }
    }

    return false;
}

// =========================================================
// FUNGSI CEK ID ITEM
// =========================================================

// Mengecek apakah ID Item sudah digunakan di dalam Inventory.
// ID Item harus unik agar setiap Item dapat dibedakan dengan jelas.
bool idItemSudahAda(string idItem, const vector<Item> &daftar_item)
{
    // Mengecek ID pada seluruh Item yang sudah tersimpan.
    for (int i = 0; i < daftar_item.size(); i++)
    {
        if (daftar_item[i].getIdItem() == idItem)
        {
            return true;
        }
    }

    return false;
}

// =========================================================
// FUNGSI TAMBAH PLAYER
// =========================================================

// Fungsi untuk membuat Player baru melalui input terminal.
// Player memiliki hubungan Composition dengan Inventory.
// Oleh karena itu, setelah membuat Player, program juga meminta data Inventory dan Item yang dimiliki oleh Player.
void tambahPlayer(vector<Player> &daftar_player, const vector<NPC> &daftar_npc)
{
    cout << endl;
    cout << "============================================" << endl;
    cout << "              TAMBAH PLAYER                 " << endl;
    cout << "============================================" << endl;

    // ---------------------------------------------------------
    // Input data Karakter
    // ---------------------------------------------------------

    // ID karakter harus unik di seluruh Player dan NPC.
    string id;

    while (true)
    {
        id = inputString("ID              : ");

        if (!idKarakterSudahAda(id, daftar_player, daftar_npc))
        {
            break;
        }

        cout << "Error: ID sudah digunakan oleh karakter lain.\n";
    }

    string nama = inputString("Nama            : ");
    int level = inputIntegerMin("Level           : ", 0);
    int maxHp = inputIntegerMin("Max HP          : ", 1);

    int hp;

    while (true)
    {
        hp = inputIntegerMin("HP              : ", 0);

        if (hp <= maxHp)
        {
            break;
        }

        cout << "Error: HP tidak boleh lebih besar dari Max HP.\n";
    }

    // ---------------------------------------------------------
    // Input data Player
    // ---------------------------------------------------------

    int exp = inputIntegerMin("Experience      : ", 0);
    int gold = inputIntegerMin("Gold            : ", 0);

    // ---------------------------------------------------------
    // Membuat Player
    // ---------------------------------------------------------

    Player player(
        id,
        nama,
        level,
        hp,
        maxHp,
        exp,
        gold);

    // ---------------------------------------------------------
    // Input Inventory
    // ---------------------------------------------------------

    int kapasitas = inputIntegerMin("Kapasitas Inventory : ", 1);

    player.getInventory().setKapasitasMaksimal(kapasitas);

    // ---------------------------------------------------------
    // Input Item
    // ---------------------------------------------------------

    // Jumlah Item tidak boleh melebihi kapasitas Inventory.
    int jumlahItem;

    while (true)
    {
        jumlahItem = inputIntegerMin("Jumlah Item        : ", 0);

        if (jumlahItem <= kapasitas)
        {
            break;
        }

        cout << "Error: jumlah Item tidak boleh melebihi kapasitas Inventory (" << kapasitas << ").\n";
    }

    for (int i = 0; i < jumlahItem; i++)
    {
        cout << endl;
        cout << "Item ke-" << i + 1 << endl;

        // ID Item harus unik di dalam Inventory Player.
        string idItem;

        while (true)
        {
            idItem = inputString("ID Item         : ");

            if (!idItemSudahAda(idItem, player.getInventory().getDaftarItem()))
            {
                break;
            }

            cout << "Error: ID Item sudah digunakan dalam Inventory Player ini.\n";
        }

        string namaItem = inputString("Nama Item       : ");
        string tipeItem = inputString("Tipe Item       : ");
        float berat = inputFloatMin("Berat (kg)      : ", 0);
        int hargaJual = inputIntegerMin("Harga Jual      : Rp", 0);
        int quantity = inputIntegerMin("Quantity        : ", 0);

        Item item(
            idItem,
            namaItem,
            tipeItem,
            berat,
            hargaJual,
            quantity);

        player.getInventory().tambahItem(item);
    }

    // ---------------------------------------------------------
    // Menambahkan Player ke vector
    // ---------------------------------------------------------

    daftar_player.push_back(player);

    cout << endl;
    cout << "Player berhasil ditambahkan." << endl;
}

// =========================================================
// FUNGSI TAMBAH NPC
// =========================================================

// Fungsi untuk membuat NPC baru melalui input terminal.
void tambahNPC(vector<NPC> &daftar_npc, const vector<Player> &daftar_player)
{
    cout << endl;
    cout << "============================================" << endl;
    cout << "                TAMBAH NPC                  " << endl;
    cout << "============================================" << endl;

    // ---------------------------------------------------------
    // Input data Karakter
    // ---------------------------------------------------------

    // ID karakter harus unik di seluruh Player dan NPC.
    string id;

    while (true)
    {
        id = inputString("ID              : ");

        if (!idKarakterSudahAda(id, daftar_player, daftar_npc))
        {
            break;
        }

        cout << "Error: ID sudah digunakan oleh karakter lain.\n";
    }

    string nama = inputString("Nama            : ");
    int level = inputIntegerMin("Level           : ", 0);
    int maxHp = inputIntegerMin("Max HP          : ", 1);
    int hp;

    while (true)
    {
        hp = inputIntegerMin("HP              : ", 0);

        if (hp <= maxHp)
        {
            break;
        }

        cout << "Error: HP tidak boleh lebih besar dari Max HP.\n";
    }

    // ---------------------------------------------------------
    // Input data NPC
    // ---------------------------------------------------------

    cout << endl;
    cout << "Tipe / peran NPC di dalam game." << endl;
    cout << "Contoh: Penjual, Pemberi Quest, atau Musuh." << endl;
    string tipeNpc = inputString("Tipe NPC        : ");

    cout << endl;
    cout << "Apakah NPC bersifat agresif dan dapat menyerang Player?" << endl;
    cout << "1 = Ya, NPC bersifat agresif/musuh." << endl;
    cout << "0 = Tidak, NPC tidak menyerang Player." << endl;

    int hostileInput;

    while (true)
    {
        hostileInput = inputInteger("Hostile? (1 = Ya, 0 = Tidak): ");

        if (hostileInput == 0 || hostileInput == 1)
        {
            break;
        }

        cout << "Error: masukkan 1 atau 0.\n";
    }

    bool isHostile = (hostileInput == 1);

    // ---------------------------------------------------------
    // Input dialog NPC
    // ---------------------------------------------------------

    int jumlahDialog = inputIntegerMin("Jumlah Dialog   : ", 1);

    vector<string> dialogList;

    for (int i = 0; i < jumlahDialog; i++)
    {
        cout << "Dialog ke-" << i + 1 << " : ";

        string dialog = inputString("");

        dialogList.push_back(dialog);
    }

    // ---------------------------------------------------------
    // Membuat NPC
    // ---------------------------------------------------------

    NPC npc(
        id,
        nama,
        level,
        hp,
        maxHp,
        tipeNpc,
        isHostile,
        dialogList);

    // ---------------------------------------------------------
    // Menambahkan NPC ke vector
    // ---------------------------------------------------------

    daftar_npc.push_back(npc);

    cout << endl;
    cout << "NPC berhasil ditambahkan." << endl;
}

// =========================================================
// FUNGSI TAMPILKAN SEMUA DATA
// =========================================================

// Fungsi untuk menampilkan seluruh Player dan NPC.
void tampilkanSemuaData(const vector<Player> &daftar_player, const vector<NPC> &daftar_npc)
{
    cout << endl;
    cout << "============================================" << endl;
    cout << "              DATA GAME                     " << endl;
    cout << "============================================" << endl;

    // ---------------------------------------------------------
    // Menampilkan Player
    // ---------------------------------------------------------

    cout << endl;
    cout << "--------------- PLAYER --------------------" << endl;

    if (daftar_player.empty())
    {
        cout << "Belum ada data Player." << endl;
    }
    else
    {
        for (int i = 0; i < daftar_player.size(); i++)
        {
            cout << endl;
            cout << "Player ke-" << i + 1 << endl;
            cout << "--------------------------------------------" << endl;

            daftar_player[i].tampilkan_info();

            cout << endl;
            cout << "Inventory:" << endl;

            daftar_player[i].getInventory().tampilkan_info();
        }
    }

    // ---------------------------------------------------------
    // Menampilkan NPC
    // ---------------------------------------------------------

    cout << endl;
    cout << "---------------- NPC ----------------------" << endl;

    if (daftar_npc.empty())
    {
        cout << "Belum ada data NPC." << endl;
    }
    else
    {
        for (int i = 0; i < daftar_npc.size(); i++)
        {
            cout << endl;
            cout << "NPC ke-" << i + 1 << endl;
            cout << "--------------------------------------------" << endl;

            daftar_npc[i].tampilkan_info();
        }
    }
}

// =========================================================
// MAIN PROGRAM
// =========================================================

int main()
{
    // =========================================================
    // DATA AWAL
    // =========================================================

    // ---------------------------------------------------------
    // Membuat Item awal
    // ---------------------------------------------------------

    Item pedang(
        "I001",
        "Pedang Besi",
        "Senjata",
        5.0,
        500,
        1);

    Item potion(
        "I002",
        "Ramuan Penyembuh",
        "Konsumsi",
        0.5,
        100,
        5);

    Item armor(
        "I003",
        "Armor Besi",
        "Armor",
        8.0,
        750,
        1);

    // ---------------------------------------------------------
    // Membuat Player awal
    // ---------------------------------------------------------

    Player player1(
        "P001",
        "Kiryu",
        10,
        100,
        100,
        2500,
        1000);

    player1.getInventory().setKapasitasMaksimal(5);
    player1.getInventory().tambahItem(pedang);
    player1.getInventory().tambahItem(potion);

    Player player2(
        "P002",
        "Akira",
        7,
        80,
        100,
        1500,
        750);

    player2.getInventory().setKapasitasMaksimal(5);
    player2.getInventory().tambahItem(armor);

    // ---------------------------------------------------------
    // Array of Object Player
    // ---------------------------------------------------------

    vector<Player> daftar_player;

    daftar_player.push_back(player1);
    daftar_player.push_back(player2);

    // ---------------------------------------------------------
    // Membuat NPC awal
    // ---------------------------------------------------------

    vector<string> dialogMerchant;

    dialogMerchant.push_back("Selamat datang di toko!");
    dialogMerchant.push_back("Apakah kamu ingin membeli sesuatu?");

    NPC merchant(
        "N001",
        "Merchant",
        5,
        80,
        80,
        "Penjual",
        false,
        dialogMerchant);

    vector<string> dialogEnemy;

    dialogEnemy.push_back("Berani sekali kamu datang ke sini!");
    dialogEnemy.push_back("Aku akan mengalahkanmu!");

    NPC goblin(
        "N002",
        "Goblin",
        8,
        120,
        120,
        "Musuh",
        true,
        dialogEnemy);

    // ---------------------------------------------------------
    // Array of Object NPC
    // ---------------------------------------------------------

    vector<NPC> daftar_npc;

    daftar_npc.push_back(merchant);
    daftar_npc.push_back(goblin);

    // =========================================================
    // MENAMPILKAN DATA AWAL
    // =========================================================

    cout << endl;
    cout << "============================================" << endl;
    cout << "       DATA GAME SEBELUM DITAMBAHKAN        " << endl;
    cout << "============================================" << endl;

    tampilkanSemuaData(daftar_player, daftar_npc);

    // =========================================================
    // MENU PROGRAM
    // =========================================================

    int pilihan;

    do
    {
        cout << endl;
        cout << "============================================" << endl;
        cout << "                MENU GAME                   " << endl;
        cout << "============================================" << endl;
        cout << "1. Tambah Player" << endl;
        cout << "2. Tambah NPC" << endl;
        cout << "3. Tampilkan Semua Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "============================================" << endl;

        pilihan = inputInteger("Pilih menu: ");

        switch (pilihan)
        {
        case 1:
            tambahPlayer(daftar_player, daftar_npc);
            break;

        case 2:
            tambahNPC(daftar_npc, daftar_player);
            break;

        case 3:
            tampilkanSemuaData(daftar_player, daftar_npc);
            break;

        case 0:
            cout << endl;
            cout << "Program selesai." << endl;
            break;

        default:
            cout << "Error: pilihan menu tidak tersedia." << endl;
            break;
        }

    } while (pilihan != 0);

    // =========================================================
    // DATA AKHIR
    // =========================================================

    // Jika user telah menambahkan data melalui menu,
    // bagian ini dapat digunakan untuk menunjukkan seluruh data terbaru sebelum program berakhir.
    cout << endl;
    cout << "============================================" << endl;
    cout << "        DATA GAME SETELAH DITAMBAHKAN       " << endl;
    cout << "============================================" << endl;

    tampilkanSemuaData(daftar_player, daftar_npc);

    return 0;
}