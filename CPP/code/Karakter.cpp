class Karakter
{
protected:
    // =========================
    // ATTRIBUTE
    // =========================

    // ID digunakan sebagai identitas unik untuk setiap karakter.
    string id;

    // Nama menyimpan nama karakter dalam game.
    string nama;

    // Level menunjukkan tingkat perkembangan karakter.
    int level;

    // HP menunjukkan jumlah health point karakter saat ini.
    int hp;

    // Max HP menunjukkan batas maksimum health point karakter.
    int max_hp;

public:
    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong.
    // Constructor ini dibuat agar object Karakter dapat dibuat tanpa memberikan nilai awal.
    Karakter() {}

    // Constructor berparameter.
    // Constructor ini digunakan untuk mengisi seluruh atribut dasar Karakter ketika object dibuat.
    Karakter(string id, string nama, int level, int hp, int max_hp)
    {
        this->id = id;
        this->nama = nama;
        this->level = level;
        this->hp = hp;
        this->max_hp = max_hp;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter id digunakan untuk mengubah ID karakter.
    void setId(string id)
    {
        this->id = id;
    }

    // Getter id digunakan untuk mengambil ID karakter.
    string getId() const
    {
        return id;
    }

    // Setter nama digunakan untuk mengubah nama karakter.
    void setNama(string nama)
    {
        this->nama = nama;
    }

    // Getter nama digunakan untuk mengambil nama karakter.
    string getNama() const
    {
        return nama;
    }

    // Setter level digunakan untuk mengubah level karakter.
    // Level tidak boleh bernilai negatif.
    void setLevel(int level)
    {
        if (level >= 0)
        {
            this->level = level;
        }
        else
        {
            cout << "Error: level tidak boleh negatif.\n";
        }
    }

    // Getter level digunakan untuk mengambil level karakter.
    int getLevel() const
    {
        return level;
    }

    // Setter hp digunakan untuk mengubah health point karakter.
    // HP harus berada di antara 0 dan max_hp.
    void setHp(int hp)
    {
        if (hp >= 0 && hp <= max_hp)
        {
            this->hp = hp;
        }
        else if (hp < 0)
        {
            cout << "Error: HP tidak boleh negatif.\n";
        }
        else
        {
            cout << "Error: HP tidak boleh melebihi max HP.\n";
        }
    }

    // Getter hp digunakan untuk mengambil health point karakter.
    int getHp() const
    {
        return hp;
    }

    // Setter max HP digunakan untuk mengubah batas maksimum HP.
    // Max HP harus lebih dari 0 dan tidak boleh lebih kecil dari HP karakter saat ini.
    void setMaxHp(int max_hp)
    {
        if (max_hp > 0 && max_hp >= hp)
        {
            this->max_hp = max_hp;
        }
        else if (max_hp <= 0)
        {
            cout << "Error: max HP harus lebih dari 0.\n";
        }
        else
        {
            cout << "Error: max HP tidak boleh lebih kecil dari HP saat ini.\n";
        }
    }

    // Getter max HP digunakan untuk mengambil batas maksimum HP.
    int getMaxHp() const
    {
        return max_hp;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi dasar Karakter.
    // Method ini dapat digunakan oleh object Karakter maupun
    // menjadi referensi bagi class turunan seperti Player dan NPC.
    void tampilkan_info() const
    {
        cout << "ID              : " << id << endl;
        cout << "Nama            : " << nama << endl;
        cout << "Level           : " << level << endl;
        cout << "HP              : " << hp << "/" << max_hp << endl;
    }

    // =========================
    // DESTRUCTOR
    // =========================

    // Destructor dipanggil ketika object Karakter dihancurkan.
    ~Karakter()
    {
    }
};