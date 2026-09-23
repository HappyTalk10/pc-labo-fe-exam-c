# 01_cache_access

記事：[基本情報技術者試験問題に挑戦しよう！「主記憶の実効アクセス時間」～C言語でつくって学ぶ～【GitHub対応】](https://pc-labo.online/2024/01/11/fe-main-memory-effective-access-time/)

配列への「順次アクセス」と「ストライドアクセス（飛び飛び）」で実行時間を比較し、CPUキャッシュのヒット率が実効アクセス時間に与える影響を体感するプログラム。

## 配置構成
```
pc-labo-fe-exam-c/
├── README.md
├── .gitignore
└── 01_cache_access/
    ├── README.md
    └── cache_access.c
```

## 実行方法

```bash
cd 01_cache_access
gcc -O2 -o cache_access cache_access.c
./cache_access
```

## 実行結果（例）

```
順次アクセス      : sum = 49999995000000, 実行時間 = 0.004072 秒
ストライドアクセス: sum = 49999995000000, 実行時間 = 0.056841 秒
倍率：ストライドアクセスは順次アクセスの約 13.96 倍
```

倍率は実行環境によって変動するが、何度実行しても順次アクセスの方が明確に速いという傾向は変わらない。
