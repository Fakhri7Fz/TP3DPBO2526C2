class Item
{
private:
    // =========================
    // ATTRIBUTE
    // =========================

    // ID item digunakan sebagai identitas unik untuk setiap Item.
    string id_item;

    // Nama item menyimpan nama barang dalam game.
    string nama_item;

    // Tipe item menunjukkan kategori item, misalnya Senjata, Konsumsi, Armor, atau Quest Item.
    string tipe_item;

    // Berat menunjukkan berat satu Item dalam satuan kilogram.
    float berat;

    // Harga jual menunjukkan nilai Item ketika dijual kepada NPC penjual.
    int harga_jual;

    // Quantity menunjukkan jumlah Item sejenis yang ditumpuk dalam satu slot Inventory.
    int quantity;

public:
    // =========================
    // CONSTRUCTOR
    // =========================

    // Constructor kosong.
    // Constructor ini dibuat agar object Item dapat dibuat tanpa memberikan nilai awal.
    Item() {}

    // Constructor berparameter.
    // Constructor ini digunakan untuk mengisi seluruh atribut Item ketika object dibuat.
    Item(string id_item, string nama_item, string tipe_item, float berat, int harga_jual, int quantity)
    {
        this->id_item = id_item;
        this->nama_item = nama_item;
        this->tipe_item = tipe_item;
        this->berat = berat;
        this->harga_jual = harga_jual;
        this->quantity = quantity;
    }

    // =========================
    // METHOD SETTER & GETTER
    // =========================

    // Setter id item digunakan untuk mengubah ID Item.
    void setIdItem(string id_item)
    {
        this->id_item = id_item;
    }

    // Getter id item digunakan untuk mengambil ID Item.
    string getIdItem() const
    {
        return id_item;
    }

    // Setter nama item digunakan untuk mengubah nama Item.
    void setNamaItem(string nama_item)
    {
        this->nama_item = nama_item;
    }

    // Getter nama item digunakan untuk mengambil nama Item.
    string getNamaItem() const
    {
        return nama_item;
    }

    // Setter tipe item digunakan untuk mengubah kategori Item.
    void setTipeItem(string tipe_item)
    {
        this->tipe_item = tipe_item;
    }

    // Getter tipe item digunakan untuk mengambil kategori Item.
    string getTipeItem() const
    {
        return tipe_item;
    }

    // Setter berat digunakan untuk mengubah berat Item.
    // Berat tidak boleh bernilai negatif.
    void setBerat(float berat)
    {
        if (berat >= 0)
        {
            this->berat = berat;
        }
        else
        {
            cout << "Error: berat item tidak boleh negatif.\n";
        }
    }

    // Getter berat digunakan untuk mengambil berat Item.
    float getBerat() const
    {
        return berat;
    }

    // Setter harga jual digunakan untuk mengubah harga jual Item.
    // Harga jual tidak boleh bernilai negatif.
    void setHargaJual(int harga_jual)
    {
        if (harga_jual >= 0)
        {
            this->harga_jual = harga_jual;
        }
        else
        {
            cout << "Error: harga jual tidak boleh negatif.\n";
        }
    }

    // Getter harga jual digunakan untuk mengambil harga jual Item.
    int getHargaJual() const
    {
        return harga_jual;
    }

    // Setter quantity digunakan untuk mengubah jumlah Item.
    // Quantity tidak boleh bernilai negatif.
    void setQuantity(int quantity)
    {
        if (quantity >= 0)
        {
            this->quantity = quantity;
        }
        else
        {
            cout << "Error: quantity tidak boleh negatif.\n";
        }
    }

    // Getter quantity digunakan untuk mengambil jumlah Item.
    int getQuantity() const
    {
        return quantity;
    }

    // =========================
    // METHOD LAIN
    // =========================

    // Menampilkan seluruh informasi Item.
    void tampilkan_info() const
    {
        cout << "ID Item         : " << id_item << endl;
        cout << "Nama Item       : " << nama_item << endl;
        cout << "Tipe Item       : " << tipe_item << endl;
        cout << "Berat           : " << berat << " kg" << endl;
        cout << "Harga Jual      : Rp" << harga_jual << endl;
        cout << "Quantity        : " << quantity << endl;
    }

    // =========================
    // DESTRUCTOR
    // =========================

    // Destructor dipanggil ketika object Item dihancurkan.
    ~Item()
    {
    }
};