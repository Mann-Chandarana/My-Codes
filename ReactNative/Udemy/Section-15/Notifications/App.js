import { useEffect } from 'react';
import { StatusBar } from 'expo-status-bar';
import { Button, StyleSheet, Text, View } from 'react-native';
import * as  Notification from 'expo-notifications'

Notification.setNotificationHandler({
  handleNotification: async () => {
    return {
      shouldPlaySound: true,
      shouldSetBadge: false,
      shouldShowAlert: true
    }
  }
});

export default function App() {

  useEffect(() => {
    async function configurePushNotifications() {
      const { status } = await Notification.getPermissionsAsync();
      let finalStatus = status;

      if (finalStatus !== 'granted') {
        const { status } = await Notification.requestPermissionsAsync();
        finalStatus = status;
      }

      if (finalStatus !== 'granted') {
        Alert.alert(
          'Permission required',
          'Push notifications need the appropriate permissions.'
        );
        return;
      }

      const expoPushToken = (await Notification.getExpoPushTokenAsync({
        projectId: 'b77530dc-352b-424f-f730-8300f975178b',
      })).data;
      console.log(expoPushToken);

      if (Platform.OS === 'android') {
        Notification.setNotificationChannelAsync('default', {
          name: 'default',
          importance: Notification.AndroidImportance.DEFAULT
        });
      }
    }

    configurePushNotifications();

  }, []);

  useEffect(() => {
    const subscription1 = Notification.addNotificationReceivedListener((notification) => {
      console.log('NOTIFICATION RECEIVED');
      console.log(notification);
      const userName = notification.request.content.data.userName;
      console.log(userName);
    });

    const subscription2 = Notification.addNotificationResponseReceivedListener((response) => {
      console.log('NOTIFICATION RESPONSE RECEIVED');
      console.log(response);
      const userName = response.notification.request.content.data.userName;
      console.log(userName);
    });

    return () => {
      subscription1.remove();
      subscription2.remove();
    };
  }, []);

  function scheduleNotificationHandler() {
    Notification.scheduleNotificationAsync({
      content: {
        title: 'My first local notification',
        body: 'This is the body of the notification.',
        data: { userName: 'Max' }
      },
      trigger: {
        seconds: 5
      }
    })
  }

  function sendPushNotificationHandler() {
    fetch('https://exp.host/--/api/v2/push/send', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({
        to: '<Your Device Push Token>]',
        title: 'Test - sent from a device!',
        body: 'This is a test!'
      })
    });
  }

  return (
    <View style={styles.container}>
      <Button
        title='Schedule Notification'
        onPress={scheduleNotificationHandler}
      />

      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
