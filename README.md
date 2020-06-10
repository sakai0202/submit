# submit
フォルダ構成  
learnC++ C++について行った学習　主にデザインパターンの学習を行っている。  
SIDESCROLLBP 作成した横スクロール+ネットワークゲームのブループリントを配置している。  

以下SIDESCROLLBPの説明  
CameraCharacter -> カメラキャラクター (観戦者)  
SideScrollCharacter -> メインキャラクター  
SideScrollGameInstance :ネットワークの接続処理が記載  
MySideScroller3GameMode : ゲームモード　マップの自動生成やログイン後にControllerが所有するプレイヤーの再設定等を行う  
LoginMenuWidget : マッチング画面のUI レベルブループリントで生成される  

・マップパターン  
BP_floortile  
BP_floortileup	:BP_floortileを継承　上り坂  
BP_floortiledown:BP_floortileを継承　下り坂  

・生成物
BP_blocker	:　障害物  
BPupperBlocker  :　スライディング用障害物  
BP_item		:　コイン  
BP_hideSight	:　観戦キャラの妨害により生成される目隠し  

SideScrollplayerController  
リスポーン処理など  

大変参考になる先達方  
・マルチプレイヤーゲームのテンプレート  
https://github.com/alwei/MultiplayerGame  

・インベーダ―ゲームの作成  
http://unrealengine-blog.hatenablog.com/entry/2014/05/01/012420  

・ロブのチュートリアル「エンドレスランナー」  
https://www.nicovideo.jp/mylist/49358712  

・ネットワークコンテンツサンプル  
公式Doc 及びContents Example : Network Fitures  
https://docs.unrealengine.com/ja/Resources/ContentExamples/Networking/index.html  
