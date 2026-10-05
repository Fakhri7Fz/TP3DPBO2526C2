class Player : public Karakter
{
private:
    // =========================
    // ATTRIBUTE
    // =========================

    // Experience point menunjukkan jumlah pengalaman yang telah diperoleh Player.
    int exp;

    // Gold menunjukkan jumlah mata uang yang dimiliki Player.
    int gold;

    // Inventory merupakan bagian dari Player yang digunakan untuk menyimpan dan mengelola item yang dimiliki Player.
    // Hubungan Player dengan Inventory merupakan Composition karena Inventory menjadi bagian dari object Player.
    Inventory inventory;

public:
    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong.
    // Constructor ini dibuat agar object Player dapat dibuat tanpa memberikan nilai awal.
    Player() {}

    // Constructor berparameter.
    // Constructor parent Karakter dipanggil melalui initializer list untuk menginisialisasi bagian Karakter dari object Player.
    // Atribut khusus Player kemudian diisi di dalam body constructor.
    // Inventory tidak perlu ditulis pada initializer list karena
    // Inventory memiliki constructor kosong dan otomatis dibuat sebagai bagian dari object Player.
    Player(string id, string nama, int level, int hp, int max_hp, int exp, int gold)
        : Karakter(id, nama, level, hp, max_hp)
    {
        this->exp = exp;
        this->gold = gold;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter exp digunakan untuk mengubah jumlah experience point Player.
    // Experience tidak boleh bernilai negatif.
    void setExp(int exp)
    {
        if (exp >= 0)
        {
            this->exp = exp;
        }
        else
        {
            cout << "Error: experience point tidak boleh negatif.\n";
        }
    }

    // Getter exp digunakan untuk mengambil jumlah experience point Player.
    int getExp() const
    {
        return exp;
    }

    // Setter gold digunakan untuk mengubah jumlah gold Player.
    // Gold tidak boleh bernilai negatif.
    void setGold(int gold)
    {
        if (gold >= 0)
        {
            this->gold = gold;
        }
        else
        {
            cout << "Error: gold tidak boleh negatif.\n";
        }
    }

    // Getter gold digunakan untuk mengambil jumlah gold Player.
    int getGold() const
    {
        return gold;
    }

    // Getter inventory digunakan ketika Inventory perlu diakses dan dimodifikasi, misalnya untuk menambahkan Item.
    Inventory &getInventory()
    {
        return inventory;
    }

    // Versi const dari getter Inventory digunakan ketika object Player bersifat const dan Inventory hanya perlu dibaca.
    // Contohnya ketika Player disimpan dalam const vector<Player>& pada fungsi tampilkanSemuaData().
    const Inventory &getInventory() const
    {
        return inventory;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi Player.
    // Atribut ID, nama, level, HP, dan max HP berasal dari class Karakter melalui inheritance.
    void tampilkan_info() const
    {
        cout << "ID              : " << id << endl;
        cout << "Nama            : " << nama << endl;
        cout << "Level           : " << level << endl;
        cout << "HP              : " << hp << "/" << max_hp << endl;
        cout << "EXP             : " << exp << endl;
        cout << "Gold            : " << gold << endl;
    }

    // =========================
    // DESTRUCTOR
    // =========================

    // Destructor dipanggil ketika object Player dihancurkan.
    // Karena Inventory merupakan bagian dari Player, object Inventory juga akan dihancurkan secara otomatis ketika object Player dihancurkan.
    ~Player()
    {
    }
};