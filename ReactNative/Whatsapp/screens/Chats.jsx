import React, { useContext } from 'react'
import { View, Text } from 'react-native'
import { collection, query } from '@firebase/firestore'
import { auth, db } from '../firebase'
import GlobalContext from '../context/Context'
import useContacts from "../hooks/useHooks";

export default function Chats() {
    const { currentUser } = auth;
    const { rooms, setRooms, setUnfilteredRooms } = useContext(GlobalContext);
    const contacts = useContacts();
    const chatsQuery = query(
        collection(db, "rooms"),
        where("participantsArray", "array-contains", currentUser.email)
    );
    useEffect(() => {
        const unsubscribe = onSnapshot(chatsQuery, (querySnapshot) => {
            const parsedChats = querySnapshot.docs.map((doc) => ({
                ...doc.data(),
                id: doc.id,
                userB: doc
                    .data()
                    .participants.find((p) => p.email !== currentUser.email),
            }));
            setUnfilteredRooms(parsedChats);
            setRooms(parsedChats.filter((doc) => doc.lastMessage));
        });
        return () => unsubscribe();
    }, []);


    return (
        <View style={{flex:1,padding:5,paddingRight:10}}>
            <Text>Chats</Text>
        </View>
    )
}