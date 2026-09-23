# pc-labo-fe-exam-c

[pc-labo.online](https://pc-labo.online/) の「基本情報技術者試験問題に挑戦しよう！」シリーズのうち、C言語で実装した学習用コードをまとめたリポジトリ。

Pythonで実装したシリーズは [pc-labo-fe-exam-python](https://github.com/HappyTalk10/pc-labo-fe-exam-python) にまとめている。ハードウェアに近い題材など、C言語の方が相性の良いテーマはこちらで扱う。

## 構成

記事ごとに `NN_トピック名` というフォルダを追加していく構成。

| フォルダ | 記事 |
|---|---|
| [01_cache_access](./01_cache_access) | [基本情報技術者試験問題に挑戦しよう！「主記憶の実効アクセス時間」～C言語でつくって確かめる～【GitHub対応】](https://pc-labo.online/2024/01/11/fe-main-memory-effective-access-time/) |

## 実行方法（共通）

各フォルダのソースをコンパイルして実行する。詳細は各フォルダのREADMEを参照。

```bash
gcc -O2 -o <実行ファイル名> <ソースファイル名>.c
./<実行ファイル名>
```