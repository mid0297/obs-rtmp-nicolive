RTMP NicoLive Plugin for OBS MultiPlatform
==========================================

ニコニコ生放送用 OBS MultiPlatform プラグイン

概要
----

ニコニコ生放送の配信用URLとストリームキーを自動取得して、[OBS MultiPlatform (obs-studio)](https://obsproject.com) で簡単に配信できるようにするプラグインです。

インストール方法
----------------

[doc/INSTALL.md](doc/INSTALL.md) をお読み下さい。

使い方
------

配信先を「ニコニコ生放送」にして、ユーザ名とパスワード、または、ユーザーセッション (ブラウザのクッキーに保存されている「user\_session\_数字\_16進数」という文字列) をいれて下さい。ブラウザで生放送枠を取得して、「配信開始」を押すとそのまま配信できます。RTMP の URL やストリームキーを手動で設定する必要はありません。

なお、ユーザ名とパスワードのみ入力した場合はセッションを一つ消費します。配信に成功した場合のみ、セッションが保存されます。

このプラグイン自体には枠を自動で取得したり、延長したりすることはできません。他のツールとあわせて使用して下さい。

### 便利かもしれない機能その1 Viqo連携 ###

「Viqoの設定を読み込む」を有効にすると、[Viqo](https://github.com/diginatu/Viqo) の設定からユーザーセッションを取得できます。Viqo を使用している人はセッションを消費しなくてすみます。

### 便利かもしれない機能その2 ビットレート調整 ###

「映像ビットレートを自動調整」を有効にすると、現在の放送枠で配信可能なビットレート値を確認し、映像ビットレートを自動的に調整してくれます。ただし、音声ビットレートは調整してくれませんので、事前に設定しておいて下さい。

### 便利かもしれない機能その3 監視 ###

「自動で配信開始と枠移動を行う」を有効にすると、監視間隔のタイミングでニコ生の情報を確認します。配信可能な放送枠があれば自動的に配信を開始し、また、配信中の放送枠が終了している場合は自動的に配信を終了します。枠が切り替わるタイミングの場合、放送終了予定時間から約10秒後に確認し、新しい放送枠があればそちらに配信を切り替えてくれます。

Viqoの自動枠取り機能とあわせて使うとほぼ自動化されて、とても楽です。

### 便利かもしれない機能その4 外部コマンドサーバー (β版) ###

「外部コマンドサーバを使用」を有効にすると、外部から操作できる TCP サーバーが内部で起動します。telnet を使ってちょっと操作から、他ツールでの本格操作まで、何でも…できるようにはなる予定です。今のところ、ユーザーセッションの設定と配信の開始/終了ができます。通信方法の詳細は [doc/PROTOCOL.md](doc/PROTOCOL.md) をお読み下さい。
