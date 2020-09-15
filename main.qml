import QtQuick 2.12
import QtQuick.Window 2.12

import Bindable 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        property int test: BindableHelper.bind(1)

        font.pointSize: 18

        // Causes complete re-evalution each update
        // leading to infinite object instances.
        text: BindableHelper.bind(1).value
    }

    Component.onCompleted: {
        console.log( BindableHelper.bind(42) )
        console.log( BindableHelper.bind(42).value )
    }
}
