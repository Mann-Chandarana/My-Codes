import { Text, View, Image, TextInput, Button, Pressable } from "react-native"
import Context from '../context/Context'
import { useContext, useState } from "react"
import { signIn, signUp } from "../firebase"

const SignIn = () => {
    const [email, setEmail] = useState("");
    const [password, setPassword] = useState("");
    const [mode, setMode] = useState("signUp")

    const { theme: { colors } } = useContext(Context);

    async function handlePress() {
        if (mode === "signUp") {
            await signUp(email, password);
        }
        if (mode === "signIn") {
            await signIn(email, password)
        }
    }
    return (
        <View
            style={{
                justifyContent: "center",
                alignItems: "center",
                flex: 1,
                backgroundColor: colors.white
            }}>
            <Text style={{ color: colors.foreground, fontSize: 24, marginBottom: 20 }}>
                Welcome to Whatsapp
            </Text>
            <Image source={require("../assets/welcome-img.png")}
                style={{ width: 180, height: 180 }}
                resizeMode="cover"
            />
            <View>
                <TextInput
                    value={email}
                    placeholder="Email"
                    onChangeText={setEmail}
                    style={{
                        paddingTop: 5,
                        borderBottomColor: colors.primary,
                        borderBottomWidth: 2,
                        width: 200,
                    }}
                />
                <TextInput
                    value={password}
                    placeholder="Password"
                    onChangeText={setPassword}
                    secureTextEntry={true}
                    style={{
                        paddingTop: 5,
                        borderBottomColor: colors.primary,
                        borderBottomWidth: 2,
                        width: 200,
                        marginTop: 20
                    }}
                />
                <View style={{ marginTop: 20 }}>
                    <Button title={mode === "signUp" ? "Sign Up" : "Login in"}
                        disabled={!password || !email}
                        color={colors.secondary}
                        onPress={handlePress} />
                </View>
                <Pressable
                    style={{ marginTop: 15 }}
                    onPress={() => mode === 'signUp' ? setMode("signIn") : setMode("signUp")}
                >
                    <Text
                        style={{ color: colors.secondaryText }}
                    >{mode === "signUp" ?
                        "Already have an account? Sign in" :
                        "Don't have an account? Sign Up"}
                    </Text>
                </Pressable>
            </View>
        </View>
    )
}

export default SignIn;