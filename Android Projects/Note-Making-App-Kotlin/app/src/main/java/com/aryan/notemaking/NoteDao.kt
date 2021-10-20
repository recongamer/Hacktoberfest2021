package com.aryan.notemaking

import androidx.lifecycle.LiveData
import androidx.room.*

@Dao
interface NoteDao {

    @Insert(onConflict = OnConflictStrategy.IGNORE)
    suspend fun insert(notes: Notes)

    @Delete
    suspend fun delete(notes: Notes)

    @Query("SELECT * FROM notes_table ORDER BY id ASC")
    fun getAllNotes():LiveData<List<Notes>>



}
