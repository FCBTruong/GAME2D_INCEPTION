; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "2048"
#define MyAppVersion "1.5"
#define MyAppPublisher "My Company, Inc."
#define MyAppURL "http://www.example.com/"
#define MyAppExeName "GAME2D_INCEPTION.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{8BD6BBB5-140A-4C29-8F5F-F955A24BCDC1}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DisableProgramGroupPage=yes
OutputDir=E:\
OutputBaseFilename=setup2048
SetupIconFile=D:\GAME2D_INCEPTION\Sources\Blackvariant-Button-Ui-Requests-2-2048.ico
Password=150520
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "D:\GAME2D_INCEPTION\Debug\GAME2D_INCEPTION.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\jpeg.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\libFLAC-8.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\libmikmod-2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\libogg-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\libpng13.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\libvorbis-0.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\libvorbisfile-3.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\SDL.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\SDL_image.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\SDL_mixer.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\SDL_ttf.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\dll\smpeg.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\1024abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\128abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\16abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\2_0abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\2_1abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\2_2abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\2_4abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\2048abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\256abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\2abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\32abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\4abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\512abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\64abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\8abc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\bkground.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\bkground2048.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\bkgroundabc.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\gameover.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\gamewin.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Images\kkkl2.gvdesign"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\guideOFF.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\guideON.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\house.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\houseOFF.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\houseON.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\pause-buttonOFF.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\pause-buttonON.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\PauseMenu.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\perspective-dice-six-faces-random.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\play-button.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\play-buttonOFF.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\play-buttonON.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\restart.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\restartOFF.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\restartON.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\speaker.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Menu\speaker-off.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Apache License.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-Black.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-BlackItalic.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-Bold.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-BoldItalic.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\RobotoCondensed-Bold.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\RobotoCondensed-BoldItalic.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\RobotoCondensed-Italic.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\RobotoCondensed-Light.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\RobotoCondensed-LightItalic.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\RobotoCondensed-Regular.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-Italic.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-Light.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-LightItalic.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-Medium.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-MediumItalic.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-Regular.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-Thin.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\roboto\Roboto-ThinItalic.ttf"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\gggmove.mp3"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\Lose.mp3"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\LoseSound.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\MoveSound.mp3"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\MoveSound.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\SoundCreateNumber.mp3"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\SoundCreateNumber.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\SoundCreateNumber123.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\SoundOFFoff.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\SoundOFFon.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\SoundONoff.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\SoundONon.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\zapsplat_multimedia_game_sound_retro_blip_006_29538.mp3"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\GAME2D_INCEPTION\Debug\Sound\zapsplat_multimedia_game_sound_retro_blip_018_29550.mp3"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{commonprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

