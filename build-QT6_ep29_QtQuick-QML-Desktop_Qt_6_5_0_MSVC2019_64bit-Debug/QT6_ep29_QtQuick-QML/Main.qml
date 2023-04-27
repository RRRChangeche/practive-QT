import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.3
import QtQml 2.3

Window {
    width: 200
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        id: button
        x: 53
        y: 104
        width: 108
        height: 89
        text: qsTr("Click")

        Connections {
            target: button
            onClicked: console.log("clicked")
        }
    }

    Text {
        id: text1
        x: 74
        y: 199
        width: 117
        height: 22
        text: qsTr("un-clicked")
        font.pixelSize: 12
    }
}
