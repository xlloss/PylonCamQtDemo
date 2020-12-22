import QtQuick 2.0
import QtQuick.Window 2.1
import QtMultimedia 5.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    VideoOutput {
        source: pylonCamera
        anchors.fill: parent
    }
}
