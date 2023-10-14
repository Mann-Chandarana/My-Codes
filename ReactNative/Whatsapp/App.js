import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, LogBox } from 'react-native';
import { useAssets } from "expo-asset";
import { useContext, useEffect, useState } from 'react';
import { SignInMethod, onAuthStateChanged } from 'firebase/auth';
import { auth } from './firebase';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { createMaterialTopTabNavigator } from '@react-navigation/material-top-tabs';
import SignIn from './screens/SignIn';
import Context from './context/Context'
import ContextWrapper from './context/ContextWrapper';
import Profile from './screens/Profile';
import Chats from './screens/Chats';
import Photo from './screens/Photo';
import { Ionicons } from "@expo/vector-icons";

LogBox.ignoreLogs([
  "Setting a timer",
  "AsyncStorage has been extracted from react-native core and will be removed in a future release.",
]);

const Stack = createNativeStackNavigator();
const Tab = createMaterialTopTabNavigator();

function App() {
  const [currUser, setCurrUser] = useState(null);
  const [loading, setLoading] = useState(true);
  const { theme: { colors } } = useContext(Context);

  useEffect(() => {
    const unsubscribe = onAuthStateChanged(auth, user => {
      setLoading(false);
      if (user) {
        setCurrUser(user)
      }
    })

    return () => unsubscribe();
  }, []);

  if (loading) {
    return <Text>Loading...</Text>
  }
  return (
    <NavigationContainer>
      {!currUser ? (
        <Stack.Navigator screenOptions={{ headerShown: false }}>
          <Stack.Screen name='signIn' component={SignIn} />
        </Stack.Navigator>
      ) :
        <Stack.Navigator screenOptions={{
          headerStyle: {
            backgroundColor: colors.foreground,
            shadowOpacity: 0,
            elevation: 0
          },
          headerTintColor: colors.white
        }}>
          {!currUser.displayName && (
            <Stack.Screen
              name='profile'
              component={Profile}
              options={{ headerShown: false }} />)
          }
          <Stack.Screen
            name='home'
            options={{ title: "Whatsapp" }}
            component={Home} />

        </Stack.Navigator>

      }
    </NavigationContainer>
  );
}

function Home() {
  const {theme: { colors }} = useContext(Context);
  return (
    <Tab.Navigator
      screenOptions={({ route }) => {
        return {
          tabBarLabel: () => {
            if (route.name === "photo") {
              return <Ionicons name="camera" size={20} color={colors.white} />;
            } else {
              return (
                <Text style={{ color: colors.white }}>
                  {route.name.toLocaleUpperCase()}
                </Text>
              );
            }
          },
          tabBarShowIcon: true,
          tabBarLabelStyle: {
            color: colors.white,
          },
          tabBarIndicatorStyle: {
            backgroundColor: colors.white,
          },
          tabBarStyle: {
            backgroundColor: colors.foreground,
          },
        };
      }}
      initialRouteName="chats"
    >
      <Tab.Screen name="photo" component={Photo} />
      <Tab.Screen name="chats" component={Chats} />
    </Tab.Navigator>
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


function Main() {
  const [assets] = useAssets(
    require("./assets/icon-square.png"),
    require("./assets/chatbg.png"),
    require("./assets/user-icon.png"),
    require("./assets/welcome-img.png")
  );
  if (!assets) {
    return <Text>Loading ..</Text>;
  }
  return <ContextWrapper><App /></ContextWrapper>
}

export default Main;
