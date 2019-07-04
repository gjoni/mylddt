# mylddt

### Download & compile
```
git clone https://github.com/gjoni/mylddt
cd mylddt
make
```

If ```make``` does not work:
```
cd src
g++ -Wall -Wno-unused-result -pedantic -O3 -mtune=native -std=c++11 *.cpp -o get_features
mv get_features ../
```

### Usage

#### Extract contacts from model using 8A distance cutoff
```
./get_features -i example/tag0001.al.pdb -j example/tag0001.al.json -d 8.0
```

#### Extract features and compare to native
```
./get_features -i example/tag0001.al.pdb -r example/native.pdb -j example/tag0001.al.json
```

#### Extract features for all files in a folder
Unpack example PDBs
```
tar xf init.tar.gz
```

#### Do feature extraction
```
./preprocessor.sh ./init ./json
```

[Jupyter notebook](https://nbviewer.jupyter.org/github/gjoni/mylddt/blob/master/data_processing.ipynb) on JSON processing.
