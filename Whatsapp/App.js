import "react-native-gesture-handler";
import { LogBox, StyleSheet, Text } from "react-native";
import { SafeAreaProvider, SafeAreaView } from "react-native-safe-area-context";
import * as SplashScreen from "expo-splash-screen";
import { useCallback, useEffect, useState } from "react";
import * as Font from "expo-font";
import AppNavigator from "./navigation/AppNavigator";
import { Provider } from "react-redux";
import { store } from "./store/store";
import { MenuProvider } from "react-native-popup-menu";
import AsyncStorage from "@react-native-async-storage/async-storage";

LogBox.ignoreLogs(["AsyncStorage has been extracted"]);
LogBox.ignoreLogs([
  "Selector unknown returned a different result when called with the same parameters. This can lead to unnecessary rerenders.",
]);
LogBox.ignoreLogs([
  "Calling getExpoPushTokenAsync without specifying a projectId is deprecated and will no longer be supported in SDK 49+",
]);
// SplashScreen.preventAutoHideAsync();
AsyncStorage.clear();

export default function App() {
  const [appIsloaded, setAppIsloaded] = useState(false);

  useEffect(() => {
    const prepare = async () => {
      try {
        await Font.loadAsync({
          black: require("./assets/fonts//Roboto-Black.ttf"),
          blackItalic: require("./assets/fonts/Roboto-BlackItalic.ttf"),
          bold: require("./assets/fonts/Roboto-Bold.ttf"),
          boldItalic: require("./assets/fonts/Roboto-BoldItalic.ttf"),
          italic: require("./assets/fonts/Roboto-Italic.ttf"),
          light: require("./assets/fonts/Roboto-Light.ttf"),
          lightItalic: require("./assets/fonts/Roboto-LightItalic.ttf"),
          medium: require("./assets/fonts/Roboto-Medium.ttf"),
          mediumItalic: require("./assets/fonts/Roboto-MediumItalic.ttf"),
          regular: require("./assets/fonts/Roboto-Regular.ttf"),
          thin: require("./assets/fonts/Roboto-Thin.ttf"),
          thinItalic: require("./assets/fonts/Roboto-ThinItalic.ttf"),
        });
      } catch (error) {
        console.log(error);
      } finally {
        setAppIsloaded(true);
      }
    };

    prepare();
  }, []);

  const onLayout = useCallback(async () => {
    if (appIsloaded) {
      await SplashScreen.hideAsync();
    }
  }, [appIsloaded]);

  if (!appIsloaded) {
    return null;
  }

  return (
    <Provider store={store}>
      <SafeAreaProvider styles={styles.container} onLayout={onLayout}>
        <MenuProvider>
          <AppNavigator />
        </MenuProvider>
      </SafeAreaProvider>
    </Provider>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
  label: {
    color: "black",
    fontSize: 18,
    fontFamily: "regular",
  },
});
